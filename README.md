# Employee-Manager

# Employee Management System in C++

## Project Overview

This Employee Management System is a simple, console-based application written in C++. It allows users to add, view, and delete employee records. The application uses basic Object-Oriented Programming (OOP) principles, file handling, and C++ STL containers (`unordered_map`) to manage employee data efficiently. Employee records are stored persistently in a text file, allowing the application to load and save employee data across sessions.

## Features

- **Add Employee**: Users can add new employees by specifying the employee's name and position. Each employee is automatically assigned a unique ID.
- **View All Employees**: Users can view all the employee records in the system.
- **Delete Employee**: Users can delete an employee by specifying their unique ID.
- **Persistent Storage**: Employee data is saved to a file, so it can be reloaded when the application is restarted.

## Prerequisites

To run this project, you'll need the following:

- A C++ compiler (e.g., GCC or MSVC).
- A terminal or command prompt to run the compiled program.

## How to Run

1. **Clone the repository**:
    ```bash
    git clone https://github.com/your-repo/employee-management-system.git
    cd employee-management-system
    ```

2. **Compile the program**:
    ```bash
    g++ -o employee_management_system main.cpp
    ```

3. **Run the executable**:
    ```bash
    ./employee_management_system
    ```

4. **Follow the prompts** to add, view, or delete employee records.

## File Structure

- `main.cpp`: The main C++ file containing the entire codebase for the Employee Management System.
- `employees.txt`: A text file where employee data is stored. This file will be created automatically if it does not exist when the program is run.

## Code Breakdown

1. **Classes**:
    - `Employee`: A class that holds the employee's `id`, `name`, and `position`.

2. **Data Structures**:
    - `unordered_map<int, Employee>`: Used to store employees by their unique ID for efficient lookup and deletion.

3. **File Handling**:
    - The employee records are saved to a file named `employees.txt`. When the program is restarted, this file is read to load the existing employees.

4. **Menu Options**:
    - **Add Employee**: Prompts the user to enter the employee’s name and position.
    - **View All Employees**: Displays all stored employee records.
    - **Delete Employee**: Allows the user to remove an employee by specifying their unique ID.

## Stretch Challenges Implemented

- **File Handling**: The program includes persistent file handling, storing employee data in a file and reloading it when the program starts.
- **Unique Employee IDs**: Ensures that each employee has a unique ID even after the program is restarted.

## Future Enhancements

- **Edit Employee Feature**: Allow users to edit an existing employee's details.
- **Search Functionality**: Add the ability to search for employees by name or position.
- **Sorting**: Display employees in sorted order by name or position.

## Known Issues

- The program does not currently handle cases where multiple employees share the same name or position.
- Employee IDs must be entered correctly when deleting an employee, with no validation for incorrect IDs.

## Video Demonstration

As part of the course requirement, a short video demonstration of the Employee Management System is recorded, showcasing the following:
1. Adding an employee.
2. Viewing all employees.
3. Deleting an employee.
4. Explanation of how the system works and the code structure.

The video has been uploaded to YouTube [here](your-video-link).

Please note that the project is also available on GitHub [here](your-repo-link).

## Contributing

1. Fork the repository.
2. Create a new feature branch (`git checkout -b feature-branch`).
3. Commit your changes (`git commit -m 'Add new feature'`).
4. Push to the branch (`git push origin feature-branch`).
5. Open a pull request.

## License

This project is licensed under the MIT License.
