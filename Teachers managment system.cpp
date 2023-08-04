#include<iostream>
#include<string.h>
#include<fstream>
#include<iomanip>
#include<cstdlib>
#include<windows.h>
#include<conio.h>

using namespace std;

struct employee {
    int employee_ID;
    char Fname[10];
    char Lname[10];
    int age;
    string gender;
    string phone_number;
    string email;
    string employment_history; // joining day
    string qualifications; // their education level
    int experience;
    string course; // what course they are teaching
    string roles; // what position do they have in their department
int  working_hours;
};
// Function prototypes
void add_employee( employee teacher ,fstream& File);
void delete_employee(fstream& File);
double calculate_salary(employee teacher , fstream& File);
void evaluate_performance(employee teacher ,fstream& File) ;
void display_all_employees(fstream& File);
void search_teacher(fstream& File) ;

int main()
{
   fstream File;
    int choice;
    struct employee teacher;
do{
    cout << "----- Teachers Management System -----\n";
    cout << "1. Add Employee\n";
    cout << "2. Delete Employee\n";
    cout << "3. Search Employee\n";
    cout << "4. Calculate Salary\n";
    cout << "5. Evaluate Performance\n";
    cout << "6. Display All Employees\n";
    cout << "0. Exit\n";
    cout<<"-------------------------------------------\n";
    cout << "Enter your choice: ";
    cin >> choice;

    switch (choice)
    {
    case 1:

        add_employee(teacher ,File);
        break;

    case 2:
        delete_employee(File);
        break;

    case 3:
    search_teacher( File);
        break;

    case 4:
        calculate_salary(teacher,File);
        break;

    case 5:
        evaluate_performance(teacher,File);
        break;

    case 6:

    display_all_employees(File);

        break;
    case 0:
        cout << "Exiting the program.\n";
        break;
    default:
        cout << "Invalid choice. Please try again.\n";
        break;
    }
    cout<<"enter any key to go back";
    cin.ignore();
    cin.get();
} while(choice!=0);
    return 0;
}

// Function to add a new employee record
void add_employee(employee teachers, fstream& File) {

    cout << "PLEASE FILL IN THE TEACHERS DATA.\n";
    File.open("teachers.txt", ios::out | ios::app);
    if (File.fail()) {
        cout << "Input file opening failed.\n";
        exit(1);
    }
employee teacher;
    // Input employee details
    cout << "Employee ID: ";
    cin >> teacher.employee_ID;
    File << teacher.employee_ID << " ";

    cout << "First Name: ";
     cin>>teacher.Fname;
    File << teacher.Fname << " ";

    cout << "Last Name: ";
     cin>>teacher.Lname;
    File << teacher.Lname << " ";

    cout << "Age: ";
    cin >> teacher.age;
    File << teacher.age << " ";

    cout << "Gender: ";
    cin.ignore();
    getline(cin, teacher.gender);
    File << teacher.gender << " ";

    cout << "Phone number: ";
    getline(cin, teacher.phone_number);
    File << teacher.phone_number << " ";

    cout << "Email Address: ";
    getline(cin, teacher.email);
    File << teacher.email << " ";

    cout << "Joining Date: ";
    getline(cin, teacher.employment_history);
    File << teacher.employment_history << " ";

    cout << "Qualification: ";
    getline(cin, teacher.qualifications);
    File << teacher.qualifications << " ";

    cout << "Experience: ";
    cin >> teacher.experience;
    File << teacher.experience << " ";

    cout << "Department: ";
    cin.ignore();
    getline(cin, teacher.course);
    File << teacher.course << " ";

    cout << "Role in their department: ";
    getline(cin, teacher.roles);
    File << teacher.roles << " ";

    File << endl;
    File.clear();
    File.close();
}

