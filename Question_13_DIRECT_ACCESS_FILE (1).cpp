#include <iostream>
#include <fstream>
using namespace std;
// Structure representing a record
struct Record 
{
    int id;
    char name[50];
};

// Function to insert a record into the direct access file
void insertRecord(fstream& file, const Record& record) 
{
    file.seekp(record.id * sizeof(Record));
    file.write(reinterpret_cast<const char*>(&record), sizeof(Record));
}

// Function to delete a record from the direct access file
void deleteRecord(fstream& file, int id) 
{
    Record record;
    file.seekp(id * sizeof(Record));
    file.write(reinterpret_cast<const char*>(&record), sizeof(Record));
}

// Function to display all records in the direct access file
void displayRecords(fstream& file) 
{
    file.seekg(0, ios::end);
    int numRecords = file.tellg() / sizeof(Record);
    file.seekg(0, ios::beg);
    for (int i = 0; i < numRecords; ++i) 
    {
        Record record;
        file.read(reinterpret_cast<char*>(&record), sizeof(Record));
        if (record.id != 0) 
        {
            cout << "ID: " << record.id << ", Name: " << record.name << endl;
        }
    }
}

int main() 
{
    fstream file("records.dat", ios::in | ios::out | ios::binary);
    // Check if the file exists, if not create a new file
    if (!file) 
    {
        file.open("records.dat", ios::out | ios::binary);
        file.close();
        file.open("records.dat", ios::in | ios::out | ios::binary);
    }

    int choice;
    do 
    {
        cout << "1. Insert record" << endl;
        cout << "2. Delete record" << endl;
        cout << "3. Display records" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice) 
        {
            case 1: 
            {
                Record record;
                cout << "Enter ID: ";
                cin >> record.id;
                cout << "Enter Name: ";
                cin.ignore(); // Ignore the newline character from previous input
                cin.getline(record.name, 50);
                insertRecord(file, record);
                break;
            }

            case 2: 
            {
                int id;
                cout << "Enter ID to delete: ";
                cin >> id;
                deleteRecord(file, id);
                break;
            }

            case 3: 
            {
                displayRecords(file);
                break;
            }

            case 4: 
            {
                cout << "Exiting..." << endl;
                break;
            }
            
            default:
            cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 4);
    file.close();
    return 0;
}