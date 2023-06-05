#include <iostream>
#include <fstream>
using namespace std;

// Structure to represent an employee
struct Employee 
{
    int employeeId;
    string name;
    string designation;
    double salary;
};

// Function to add an employee record to the file
void addEmployee(const Employee& employee) 
{
    ofstream file("employee_data.txt", ios::binary | ios::app);
    if (!file) 
    {
        cout << "Error opening the file.\n";
        return;
    }
    file.write(reinterpret_cast<const char*>(&employee), sizeof(Employee));
    file.close();
}

// Function to delete an employee record from the file
void deleteEmployee(int employeeId) 
{
    ifstream inFile("employee_data.txt", ios::binary);
    if (!inFile) 
    {
        cout << "Error opening the file.\n";
        return;
    }
    ofstream outFile("temp.txt", ios::binary);
    if (!outFile) 
    {
        cout << "Error opening the file.\n";
        inFile.close();
        return;
    }
    Employee employee;
    bool found = false;
    while (inFile.read(reinterpret_cast<char*>(&employee), sizeof(Employee))) 
    {
        if (employee.employeeId != employeeId)
        outFile.write(reinterpret_cast<const char*>(&employee), sizeof(Employee));
        else
        found = true;
    }
    inFile.close();
    outFile.close();
    if (found) 
    {
        remove("employee_data.txt");
        rename("temp.txt", "employee_data.txt");
        cout << "Employee deleted successfully.\n";
    } 
    else 
    {
        remove("temp.txt");
        cout << "Employee not found.\n";
    }
}

// Function to display information of a particular employee
void displayEmployee(int employeeId) 
{
    ifstream file("employee_data.txt", ios::binary);
    if (!file) 
    {
        cout << "Error opening the file.\n";
        return;
    }
    Employee employee;
    bool found = false;
    while (file.read(reinterpret_cast<char*>(&employee), sizeof(Employee))) 
    {
        if (employee.employeeId == employeeId) 
        {
            cout << "Employee ID: " << employee.employeeId << endl;
            cout << "Name: " << employee.name << endl;
            cout << "Designation: " << employee.designation << endl;
            cout << "Salary: " << employee.salary << endl;
            found = true;
            break;
        }
    }
    file.close();
    if (!found)
    cout << "Employee not found.\n";
}

int main() 
{
    int choice;
    Employee employee;
    do 
    {
        cout << "1. Add employee\n";
        cout << "2. Delete employee\n";
        cout << "3. Display employee information\n";
        cout << "4. Quit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice) 
        {
            case 1:
            cout << "Enter employee ID: ";
            cin >> employee.employeeId;
            cout << "Enter name: ";
            cin.ignore();
            getline(cin, employee.name);
            cout << "Enter designation: ";
            getline(cin, employee.designation);
            cout << "Enter salary: ";
            cin >> employee.salary;
            addEmployee(employee);
            break;

            case 2:
            cout << "Enter employee ID to delete: ";
            cin >> employee.employeeId;
            deleteEmployee(employee.employeeId);
            break;

            case 3:
            cout << "Enter employee ID to display: ";
            cin >> employee.employeeId;
            displayEmployee(employee.employeeId);
            break;
            
            case 4:
            cout << "Exiting the program.\n";
            break;
            default:
            cout << "Invalid choice. Please try again.\n";
        }
    } 
    while (choice != 4);
    return 0;
}
