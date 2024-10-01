#include <iostream>
#include <string>
#include <unordered_map>
#include <fstream> // For file handling
#include <sstream> // For stringstream

// Employee class to store employee data
class Employee {
    public:
        int id;
        std::string name;
        std::string position;

        // Default constructor
        Employee() : id(0), name(""), position("") {}

        // Constructor with parameters
        Employee(int empId, std::string empName, std::string empPosition)
            : id(empId), name(empName), position(empPosition) {}
};

// Global variable to set the first employee ID to 1
int currentEmployeeID = 1;

// Check tl see if the employee list is empty
void checkIfEmpty(const std::unordered_map<int, Employee>& employeeMap) {

    if (employeeMap.empty()) {
        std::cout << "There are no employees in the register to perform actions on\n";
        return;
    }
}

// Function to display all employees
void displayAllEmployees(const std::unordered_map<int, Employee>& employeeMap) {
    // if (employeeMap.empty()) {
    //     std::cout << "No employees to display.\n";
    //     return;
    // }
    checkIfEmpty(employeeMap);

    for (const auto& pair : employeeMap) {
        const Employee& emp = pair.second;
        std::cout << "ID: " << emp.id
                  << ", Name: " << emp.name
                  << ", Position: " << emp.position << "\n";
    }
}

// Function to load employees from a file into the employeeMap
void loadEmployeesFromFile(std::unordered_map<int, Employee>& employeeMap, const std::string& filename) {
    std::ifstream inFile(filename);
    if (!inFile) {
        std::cout << "No existing employee file found. Creating a new file to work with.\n";
        return;
    }

    std::string line;
    while (std::getline(inFile, line)) {
        std::stringstream ss(line);
        int id;
        std::string name, position;

        ss >> id;
        ss.ignore(); // Ignore space after id
        std::getline(ss, name, ','); // Read name until comma
        std::getline(ss, position); // Read rest as position

        Employee employee(id, name, position);
        employeeMap[id] = employee;

        if (id >= currentEmployeeID) {
            currentEmployeeID = id + 1; // Ensure the ID is always unique
        }
    }
    inFile.close();
}

// Function to save employees from employeeMap into a file
void saveEmployeesToFile(const std::unordered_map<int, Employee>& employeeMap, const std::string& filename) {
    std::ofstream outFile(filename);
    for (const auto& pair : employeeMap) {
        const Employee& emp = pair.second;
        outFile << emp.id << " " << emp.name << "," << emp.position << "\n";
    }
    outFile.close();
}

// Function to add an employee
void addEmployee(std::unordered_map<int, Employee>& employeeMap, const std::string& filename) {
    std::string name, position;

    std::cout << "Enter Employee Name: ";
    std::cin.ignore();
    std::getline(std::cin, name);

    std::cout << "Enter Employee Position: ";
    std::getline(std::cin, position);

    Employee newEmployee(currentEmployeeID, name, position);
    employeeMap[currentEmployeeID] = newEmployee;

    std::cout << "Employee added successfully! Assigned ID: " << currentEmployeeID << "\n";

    currentEmployeeID++;
    saveEmployeesToFile(employeeMap, filename); // Save updates to the file
}

// Function to delete an employee
void deleteEmployee(std::unordered_map<int, Employee>& employeeMap, const std::string& filename) {
    displayAllEmployees(employeeMap); // Show the list before deletion
   
   // Used to prevent the user from being prompted to delete a user if there are none
    if (employeeMap.empty()) {
        return;
    }
    
    // Code used to delete a desired user
    int id;
    std::cout << "Enter Employee ID to delete or press 0 if no employee is to be deleted: ";
    std::cin >> id;

    auto it = employeeMap.find(id);
    if (it != employeeMap.end() and id != 0) {
        employeeMap.erase(it);
        std::cout << "Employee deleted successfully!\n";
        saveEmployeesToFile(employeeMap, filename); // Save updates to the file
    } else if (id == 0) {
        std::cout << "Canceling the employee record deletion process\n";
        return;
    } else {
        std::cout << "Employee not found.\n";
    }
}

// Function to display the menu and get user choice
int displayMenu() {
    std::cout << "\n=== Employee Management System ===\n";
    std::cout << "1. Add Employee\n";
    std::cout << "2. View All Employees\n";
    std::cout << "3. Delete Employee\n";
    std::cout << "4. Exit\n";
    std::cout << "Enter your choice: ";
    int choice;
    std::cin >> choice;
    return choice;
}

int main() {
    std::unordered_map<int, Employee> employeeMap;
    std::string filename = "employees.txt";

    // Load employees from file at the start
    loadEmployeesFromFile(employeeMap, filename);

    while (true) {
        int choice = displayMenu();

        switch (choice) {
        case 1:
            addEmployee(employeeMap, filename);
            break;
        case 2:
            displayAllEmployees(employeeMap);
            break;
        case 3:
            deleteEmployee(employeeMap, filename);
            break;
        case 4:
            std::cout << "Exiting...\n";
            return 0;
        default:
            std::cout << "Invalid choice. Please choose one of the option choices above.\n";
        }
    }

    return 0;
}
