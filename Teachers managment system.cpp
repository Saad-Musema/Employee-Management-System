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

void search_teacher(fstream& File) {
    int ID,count=0;
    cout<<"Enter the employee ID you want to search:";
    cin>>ID;
    employee teacher;
    employee teachers[10];
    File.open("teachers.txt",ios::in);
    File>>teacher.employee_ID>>teacher.Fname>>teacher.Lname>>teacher.age>> teacher.gender
               >> teacher.phone_number >> teacher.email >> teacher.employment_history
              >> teacher.qualifications >> teacher.experience >> teacher.course >> teacher.roles;

    while(!File.eof())
        {
        if (teacher.employee_ID == ID) {
            cout << "Teacher Found:\n";
            cout << "Employee ID: " << teacher.employee_ID << endl;
            cout << "Name: " << teacher.Fname << " "<< teacher.Lname<< endl;
            cout << "Age: " << teacher.age << endl;
            cout << "Gender: " << teacher.gender << endl;
          cout << "Phone number: " << teacher.phone_number << endl;
            cout << "Email Address: " << teacher.email << endl;
            cout << "Joining Date: " << teacher.employment_history << endl;
            cout << "Qualification: " << teacher.qualifications << endl;
            cout << "Experience: " << teacher.experience << endl;
            cout << "Department: " << teacher.course << endl;
            cout << "Role in their department: " << teacher.roles << endl;
           count++;

            }


            File.clear();
            File>>teacher.employee_ID>>teacher.Fname>>teacher.Lname>>teacher.age>>teacher.gender>>teacher.email>>teacher.employment_history>>teacher.qualifications>>
            teacher.experience>>teacher.course>>teacher.roles;
    }

     if (count == 0) {
        cout << "Teacher with Employee ID " << ID << " not found.\n";
    }
}

 void delete_employee(fstream& File)
    {
        int ID, count = 0;
    cout << "DELETE TEACHER" << endl;
    cout << "Enter Teacher's ID you want to delete: ";
    cin >> ID;
    employee teacher;

    File.open("teachers.txt", ios::in);
    ofstream tempfile;
    tempfile.open("temporary.txt", ios::out);

    while (
           File >> teacher.employee_ID >> teacher.Fname >> teacher.Lname >> teacher.age >> teacher.gender >> teacher.phone_number >> teacher.email >> teacher.experience >> teacher.employment_history >> teacher.qualifications >> teacher.course >> teacher.roles)
    {
        if (teacher.employee_ID != ID) {
            tempfile << teacher.employee_ID << " " << teacher.Fname << " " << teacher.Lname << " " << teacher.age << " " << teacher.gender << " " << teacher.phone_number << " " << teacher.email << " " << teacher.experience << " " << teacher.employment_history << " " << teacher.qualifications << " " << teacher.course << " " << teacher.roles << endl;

        }else
        count++;
    }

    File.close();
    tempfile.close();
    remove("teachers.txt");
    rename("temporary.txt", "teachers.txt");

    if (count == 0) {
       cout << "Employee record not found!" << endl;

    } else
        cout << "Employee record deleted successfully!" << endl;
}


void evaluate_performance(employee teacher, fstream& File) {
int ID;
cout<<"Enter the employee ID :";
    cin>>ID;
    int hoursWorked;
    int weeklyHours;
    cout << "Enter working hours weekly : ";
    cin>>weeklyHours;
    teacher.working_hours = 4* weeklyHours;
    int totalworked;
    for(int i=0; i<4; i++){
        cout<<"How many hours did you work in week "<<i+1<<" ?";
        cin>>hoursWorked;
        totalworked += hoursWorked;}
            if (totalworked == teacher.working_hours) {
        cout << "Excellent performance\n";
    } else if (totalworked >= (0.75 * teacher.working_hours)) {
        cout << "Good performance\n";
    } else if (totalworked >= (0.50 * teacher.working_hours)) {
        cout << "Bad performance\n";
    } else if (totalworked >= 0) {
        cout << "Very bad performance\n";
    } else {
        cout << "Invalid input\n";
    }
}

