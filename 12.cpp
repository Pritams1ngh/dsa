#include<iostream>
#include<fstream>
#include<iomanip>
using namespace std;

void addelement()
{
    ofstream f("db.txt" , ios :: app);

    string name,desg,salary;
    string id;
    cout<<"\nEnter ID : ";
    cin>>id;
    cout<<"\nEnter name : ";
    cin>>name;
    cout<<"\nEnter Designation : ";
    cin>>desg;
    cout<<"\nEnter Salary : ";
    cin>>salary;

    f << left << setw(20) << id << setw(20) << name << setw(20) << desg << setw(20) << salary <<endl ;
    f.close();
    cout<<"\nEmplyee Added Succesfully!!";
}

void searchelement()
{
    ifstream f("db.txt");
    string id;
    string line;
    cout<<"\nEnter ID to be searched : ";
    cin>>id;
    bool found = false ;
    while(getline(f,line))
    {
        if(line.find(id) != string :: npos)  
        {
                cout<<"\nEmployee is : "<<endl;
                cout<<line<<endl;
                found = true;
                break;
        } 
    }
    
    f.close();

    if(!found)
    {
        cout<<"\nEmployee Dosen't Exists!!"<<endl;
    }
}

void deleteelement()
{
    ifstream f("db.txt");
    string id;
    string line;
    string filedata;
    cout<<"\nEnter ID to deleted : ";
    cin>>id;
    

    while(getline(f,line))
    {
        if(line.find(id) == string :: npos)  
        {
                filedata += line;
                filedata += "\n";
        } 
    }
    f.close();

    ofstream f1("db.txt", ios :: out);
    f1<<filedata;
    f1.close();
}

void printelement()
{
    ifstream f("db.txt");
    string line;
    cout<<"\nPrinting File data"<<endl;
    while(getline(f,line))
    {
        cout<<line<<endl;
    }
    cout<<"\nPrinting Completed";
    f.close();
    
}

int main()
{

    ofstream f("db.txt" , ios :: out);
    f << left << setw(20) <<"Emplyee ID"<< setw(20) << "Name" << setw(20) <<"Designation"<< setw(20) <<"Salary" <<endl;
    f.close();
    int ch;

    while(ch != 5)
    {
        
        cout << "1. Add employee\n";
        cout << "2. Delete employee\n";
        cout << "1. Search employee\n";
        cout << "3. Display employee information\n";
        cout << "4. Quit\n";
        cout<<"\nEnter Your Choice : ";
        
        cin>>ch;

        switch(ch)
        {
            case 1:
                addelement();
                break;
            case 2:
                deleteelement();
                break;
            case 3:
                searchelement();
                break;
            case 4:
                printelement();
                break;
            case 5:
                return 0;
                break;
            default:
                cout<<"\nEnter Valid Choice!";

        }
    }
    return 0;
}