#include <iostream>
#include <queue>
using namespace std;
// Structure to represent a patient
struct Patient 
{
    string name;
    int priority;
    // Constructor
    Patient(string n, int p) : name(n), priority(p) {}
    // Overloading the comparison operator for priority queue
    bool operator<(const Patient& other) const 
    {
        // Higher priority value means higher priority
        return priority > other.priority;
    }
};

int main() 
{
    // Creating a priority queue of patients
    priority_queue<Patient> patientQueue;
    // Adding patients to the priority queues
    patientQueue.push(Patient("John Doe", 1)); // serious
    patientQueue.push(Patient("Jane Smith", 2)); // non-serious
    patientQueue.push(Patient("Mike Johnson", 3)); // general checkup
    patientQueue.push(Patient("Emily Brown", 2)); // non-serious
    // Serving patients in priority order
    while (!patientQueue.empty()) 
    {
        Patient currentPatient = patientQueue.top();
        patientQueue.pop();
        // Process the patient (you can replace this with any desired functionality)
        cout << "Processing patient: " << currentPatient.name << endl;
    }
    return 0;
}