#include<iostream>
#include<string.h>
#include<fstream>
#include<cstdlib>
#include<conio.h>

using namespace std;

struct Employee {
    int employee_ID;
    char Fname[10];
    char Lname[10];
    int age;
    string gender;
    string phone_number;
    string email;
    string employment_history;//joining date
    string qualifications;//masters
    int experience;
    string course;
    string roles;
    int working_hours;
};

fstream file;

void employee_insert(Employee &emp) {
    system("cls");
    cout<<"\t\t\tEnter ID: ";
    cin>>emp.employee_ID;
    cout << "\t\t\tEnter First Name: ";
    cin >> emp.Fname;
    cout << "\t\t\tEnter Last Name: ";
    cin >> emp.Lname;
    cout << "\t\t\tEnter Age: ";
    cin >> emp.age;
    cout << "\t\t\tEnter Gender: ";
    cin >> emp.gender;
    cout << "\t\t\tEnter Phone Number: ";
    cin >> emp.phone_number;
    cout << "\t\t\tEnter Email: ";
    cin >> emp.email;
    cout << "\t\t\tEnter Joining date(dd/mm/yyyy): ";
    cin >> emp.employment_history;
    cout << "\t\t\tEnter Qualifications(Bsc,Msc,Phd): ";
    cin >> emp.qualifications;
    cout << "\t\t\tEnter Experience(in year): ";
    cin >> emp.experience;
    cout << "\t\t\tEnter Course: ";
    cin >> emp.course;
    cout << "\t\t\tEnter Roles(in a department): ";
    cin >> emp.roles;
    cout << "\t\t\tEnter Working Hours(perweek): ";//weekly expected hour
    cin >> emp.working_hours;

    file.open("employeeRecord.txt", ios::app | ios::out);
    file << emp.employee_ID << " " << emp.Fname << " " << emp.Lname << " " << emp.age << " " << emp.gender << " " << emp.phone_number << " " << emp.email << " " << emp.employment_history << " " << emp.qualifications << " " << emp.experience << " " << emp.course << " " << emp.roles << " " << emp.working_hours << "\n";
    file.close();
}

void employee_display(Employee emp) {
    system("cls");
    int total = 1;
    cout << "\n-------------------------------------------------------------------------------------------------------" << endl;
    cout << "------------------------------------- Employee Record Table --------------------------------------------" << endl;

    file.open("employeeRecord.txt", ios::in);

    if (!file) {
        cout << "\n\t\t\tError while opening file!!!! ";
    }
     else {
        while (file >> emp.employee_ID >> emp.Fname >> emp.Lname >> emp.age >> emp.gender >> emp.phone_number >> emp.email >> emp.employment_history >> emp.qualifications >> emp.experience >> emp.course >> emp.roles >> emp.working_hours) {
            cout << "\n\n\t\t\tEmployee No: " << total++ << endl;
            cout << "\t\t\tID: " << emp.employee_ID << "\n";
            cout << "\t\t\tFirst Name: " << emp.Fname << "\n";
            cout << "\t\t\tLast Name: " << emp.Lname << "\n";
            cout << "\t\t\tAge: " << emp.age << "\n";
            cout << "\t\t\tGender: " << emp.gender << "\n";
            cout << "\t\t\tPhone Number: " << emp.phone_number << "\n";
            cout << "\t\t\tEmail: " << emp.email << "\n";
            cout << "\t\t\tEmployment History: " << emp.employment_history << "\n";
            cout << "\t\t\tQualifications: " << emp.qualifications << "\n";
            cout << "\t\t\tExperience: " << emp.experience << "\n";
            cout << "\t\t\tCourse: " << emp.course << "\n";
            cout << "\t\t\tRoles: " << emp.roles << "\n";
            cout << "\t\t\tWorking Hours: " << emp.working_hours << "\n";
        }

        if (total == 1) {
            cout << "\n\t\t\tNo Data is Present..." << endl;
        }
    }

    file.close();
}


void employee_modify(Employee &emp) {

{
    system("cls");
    fstream file, file1;
    int employeeID;
    int found = 0;

    cout << "\n-------------------------------------------------------------------------------------------------------" << endl;
    cout << "------------------------------------- Employee Modification Details ----------------------------------------" << endl;

    file.open("employeeRecord.txt", ios::in);
    if (!file)
    {
        cout << "\n\t\t\tError while opening file!!!! ";
        file.close();
    }
    else
    {
        cout << "\nEnter Employee ID which you want to Modify: ";
        cin >> employeeID;
        file1.open("temp.txt", ios::app | ios::out);

        while (file >> emp.employee_ID >> emp.Fname >> emp.Lname >> emp.age >> emp.gender >> emp.phone_number >> emp.email >> emp.employment_history >> emp.qualifications >> emp.experience >> emp.course >> emp.roles >> emp.working_hours)
        {
            if (employeeID != emp.employee_ID)
            {
                file1 << " " << emp.employee_ID << " " << emp.Fname << " " << emp.Lname << " " << emp.age << " " << emp.gender << " " << emp.phone_number << " " << emp.email << " " << emp.employment_history << " " << emp.qualifications << " " << emp.experience << " " << emp.course << " " << emp.roles << " " << emp.working_hours << "\n";
            }
            else
            {
                cout << "\n-------------------------------------------------------------------------------------------------------" << endl;
                cout << "------------------------------------- Modifing Employee Details ----------------------------------------" << endl;
               cout << "\t\t\tEnter ID: ";
                cin >> emp.employee_ID;
                cout << "\t\t\tEnter First Name: ";
                cin >> emp.Fname;
                cout << "\t\t\tEnter Last Name: ";
                cin >> emp.Lname;
                cout << "\t\t\tEnter Age: ";
                cin >> emp.age;
                cout << "\t\t\tEnter Gender: ";
                cin >> emp.gender;
                cout << "\t\t\tEnter Phone Number: ";
                cin >> emp.phone_number;
                cout << "\t\t\tEnter Email: ";
                cin >> emp.email;
                cout << "\t\t\tEnter Employment History: ";
                cin >> emp.employment_history;
                cout << "\t\t\tEnter Qualifications: ";
                cin >> emp.qualifications;
                cout << "\t\t\tEnter Experience: ";
                cin >> emp.experience;
                cout << "\t\t\tEnter Course: ";
                cin >> emp.course;
                cout << "\t\t\tEnter Roles: ";
                cin >> emp.roles;
                cout << "\t\t\tEnter Working Hours: ";
                cin >> emp.working_hours;

                file1 << " " << emp.employee_ID << " " << emp.Fname << " " << emp.Lname << " " << emp.age << " " << emp.gender << " " << emp.phone_number << " " << emp.email << " " << emp.employment_history << " " << emp.qualifications << " " << emp.experience << " " << emp.course << " " << emp.roles << " " << emp.working_hours << "\n";
                found++;
            }
        }

        file.close();
        file1.close();

        if (found == 0)
        {
            cout << "\n\n\t\t\t Employee ID Not Found....";
        }

        remove("employeeRecord.txt");
        rename("temp.txt", "employeeRecord.txt");
    }
}
}

void employee_search(Employee emp) {
    system("cls");
    file.open("employeeRecord.txt", ios::in);

    if (!file) {
        cout << "\n-------------------------------------------------------------------------------------------------------" << endl;
        cout << "------------------------------------- Employee Search Data --------------------------------------------" << endl;
        cout << "\n\t\t\tError while opening file!!!! ";
    } else {
        int found = 0;
        int employeeID;

        cout << "\n-------------------------------------------------------------------------------------------------------" << endl;
        cout << "------------------------------------- Employee Search Table --------------------------------------------" << endl;
        cout << "\nEnter Employee ID of Employee you want to search: ";
        cin >> employeeID;

        while (file >> emp.employee_ID >> emp.Fname >> emp.Lname >> emp.age >> emp.gender >> emp.phone_number >> emp.email >> emp.employment_history >> emp.qualifications >> emp.experience >> emp.course >> emp.roles >> emp.working_hours) {
            if (employeeID == emp.employee_ID) {
                cout << "\n\t\t\tEmployee ID: " << emp.employee_ID << "\n";
                cout << "\t\t\tFirst Name: " << emp.Fname << "\n";
                cout << "\t\t\tLast Name: " << emp.Lname << "\n";
                cout << "\t\t\tAge: " << emp.age << "\n";
                cout << "\t\t\tGender: " << emp.gender << "\n";
                cout << "\t\t\tPhone Number: " << emp.phone_number << "\n";
                cout << "\t\t\tEmail: " << emp.email << "\n";
                cout << "\t\t\tEmployment History: " << emp.employment_history << "\n";
                cout << "\t\t\tQualifications: " << emp.qualifications << "\n";
                cout << "\t\t\tExperience: " << emp.experience << "\n";
                cout << "\t\t\tCourse: " << emp.course << "\n";
                cout << "\t\t\tRoles: " << emp.roles << "\n";
                cout << "\t\t\tWorking Hours: " << emp.working_hours << "\n";
                found++;
            }
        }

        if (found == 0) {
            cout << "\n\t\t\t Employee ID Not Found....";
        }

        file.close();
    }
}
void calculate_salary(Employee &emp) {
system("cls");
int found = 0;

    file.open("employeeRecord.txt", ios::in);
if (!file) {
        cout << "\n-------------------------------------------------------------------------------------------------------" << endl;
        cout << "\n\t\t\tError while opening file!!!! ";
    } else {
        int ID;
    cout << "Enter the employee ID: ";
    cin >> ID;
   while( file >> emp.employee_ID >> emp.Fname >> emp.Lname >> emp.age >> emp.gender >> emp.phone_number >> emp.email >> emp.employment_history >> emp.qualifications >> emp.experience >> emp.course >> emp.roles >> emp.working_hours)
{
       if (ID==emp.employee_ID){
    int hoursWorked;
    int totalWorked = 0; // Initialize totalWorked to 0
    for (int i = 0; i < 4; i++) {
        cout << "How many hours did you work in week " << i + 1 << "? ";
        cin >> hoursWorked;
        totalWorked += hoursWorked; // Accumulate total worked hours
    }

    double paymentPerHour = 500.0;
    double salary = paymentPerHour * totalWorked;
    cout << "The salary of " << emp.Fname << " " << emp.Lname << " is: " << salary << " birr" << endl;
    found++;
   // Return the calculated salary


    }
    }
    if (found == 0) {
            cout << "\n\t\t\t Employee ID Not Found....";
}
        }
file.close();
}



void evaluate_performance(Employee &emp) {
   system("cls");
int found = 0;

    file.open("employeeRecord.txt", ios::in);
if (!file) {
        cout << "\n-------------------------------------------------------------------------------------------------------" << endl;
        cout << "\n\t\t\tError while opening file!!!! ";
    } else {
        int ID;
    cout << "Enter the employee ID: ";
    cin >> ID;
   while( file >> emp.employee_ID >> emp.Fname >> emp.Lname >> emp.age >> emp.gender >> emp.phone_number >> emp.email >> emp.employment_history >> emp.qualifications >> emp.experience >> emp.course >> emp.roles >> emp.working_hours)
{

    if (ID==emp.employee_ID){
        int hoursWorked;//actual weekly worked hours
    int montly_working_hours;
    montly_working_hours = 4 * emp.working_hours;//Expected_monthly_Hours
    int totalWorked = 0; // Initialize totalWorked to 0
    for (int i = 0; i < 4; i++) {
        cout << "How many hours did you work in week " << i + 1 << "? ";
        cin >> hoursWorked;
        totalWorked += hoursWorked; // Accumulate total worked hours
    }

    if (totalWorked == montly_working_hours) {
        cout << "Excellent performance\n";
    } else if (totalWorked >= (0.75 * montly_working_hours)) {
        cout << "Good performance\n";
    } else if (totalWorked >= (0.50 * montly_working_hours)) {
        cout << "Bad performance\n";
    } else if (totalWorked >= 0) {
        cout << "Very bad performance\n";
    } else {
        cout << "Invalid input\n";
    }
      found++;
    }}

}

if (found == 0) {
            cout << "\n\t\t\t Employee ID Not Found....";
        }
file.close();

}


void menu() {
   Employee emp;
   int choice;
    do {
        char x;
        system("cls");
        cout << "\t\t\t----- Teachers Management System -----\n";
        cout << "\t\t\t 1. Enter New Employee Record" << endl;
        cout << "\t\t\t 2. Display Employee Records" << endl;
        cout << "\t\t\t 3. Update Employee Record" << endl;
        cout << "\t\t\t 4. Search Employee Record" << endl;
         cout << "\t\t\t 5. calculate Employee Record" << endl;
         cout << "\t\t\t 6. evaluation Employee Record" << endl;
        cout << "\t\t\t 7. Exit" << endl;
        cout<<"\t\t\t-------------------------------------------\n";
        cout << "\n Enter Your Choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                do {

                    employee_insert(emp);
                    cout << "Do you want to add another employee record? (y/n): ";
                    cin >> x;
                } while (x == 'y' || x == 'Y');
                break;
            case 2:
                {

                    employee_display(emp);
                    break;
                }
            case 3:
                {
                    employee_modify(emp);
                    break;
                }
            case 4:
                {

                    employee_search(emp);
                    break;
                }

            case 5:
                {

                    calculate_salary(emp);
                    break;
                }
            case 6:
                {

                   evaluate_performance(emp);
                   break;
                }
            case 7:
                cout << "\n\t\t\t Program Is Exiting..." << endl;
                exit(0);
                break;
            default:
                cout << "\n\t\t\t Invalid Choice... Please Try Again..." << endl;
        }
cout<<"\nEnter any key to go back to the menu";
        getch();

    } while (choice != 7);
}

int main() {

    menu();
    return 0;
}
#include<iostream>
#include<string.h>
#include<fstream>
#include<iomanip>
#include<cstdlib>
#include<windows.h>
#include<conio.h>

using namespace std;

struct Employee {
    int employee_ID;
    char Fname[10];
    char Lname[10];
    int age;
    string gender;
    string phone_number;
    string email;
    string employment_history;
    string qualifications;
    int experience;
    string course;
    string roles;
    int working_hours;
}emp;

fstream file;

void employee_insert(Employee &emp) {
    system("cls");
    cout<<"\t\t\tEnter ID: ";
    cin>>emp.employee_ID;
    cout << "\t\t\tEnter First Name: ";
    cin >> emp.Fname;
    cout << "\t\t\tEnter Last Name: ";
    cin >> emp.Lname;
    cout << "\t\t\tEnter Age: ";
    cin >> emp.age;
    cout << "\t\t\tEnter Gender: ";
    cin >> emp.gender;
    cout << "\t\t\tEnter Phone Number: ";
    cin >> emp.phone_number;
    cout << "\t\t\tEnter Email: ";
    cin >> emp.email;
    cout << "\t\t\tEnter Employment History: ";
    cin >> emp.employment_history;
    cout << "\t\t\tEnter Qualifications: ";
    cin >> emp.qualifications;
    cout << "\t\t\tEnter Experience: ";
    cin >> emp.experience;
    cout << "\t\t\tEnter Course: ";
    cin >> emp.course;
    cout << "\t\t\tEnter Roles: ";
    cin >> emp.roles;
    cout << "\t\t\tEnter Working Hours: ";
    cin >> emp.working_hours;

    file.open("employeeRecord.txt", ios::app | ios::out);
    file << emp.employee_ID << " " << emp.Fname << " " << emp.Lname << " " << emp.age << " " << emp.gender << " " << emp.phone_number << " " << emp.email << " " << emp.employment_history << " " << emp.qualifications << " " << emp.experience << " " << emp.course << " " << emp.roles << " " << emp.working_hours << "\n";
    file.close();
}

void employee_display(Employee &emp) {
    system("cls");
    fstream file;
    int total = 1;

    cout << "\n-------------------------------------------------------------------------------------------------------" << endl;
    cout << "------------------------------------- Employee Record Table --------------------------------------------" << endl;

    file.open("employeeRecord.txt", ios::in);

    if (!file) {
        cout << "\n\t\t\tNo Data is Present... ";
        file.close();
    } else {
        while (file >> emp.employee_ID >> emp.Fname >> emp.Lname >> emp.age >> emp.gender >> emp.phone_number >> emp.email >> emp.employment_history >> emp.qualifications >> emp.experience >> emp.course >> emp.roles >> emp.working_hours) {
            cout << "\n\n\t\t\tEmployee No.: " << total++ << endl;
            cout << "\t\t\tID: " << emp.employee_ID << "\n";
            cout << "\t\t\tFirst Name: " << emp.Fname << "\n";
            cout << "\t\t\tLast Name: " << emp.Lname << "\n";
            cout << "\t\t\tAge: " << emp.age << "\n";
            cout << "\t\t\tGender: " << emp.gender << "\n";
            cout << "\t\t\tPhone Number: " << emp.phone_number << "\n";
            cout << "\t\t\tEmail: " << emp.email << "\n";
            cout << "\t\t\tEmployment History: " << emp.employment_history << "\n";
            cout << "\t\t\tQualifications: " << emp.qualifications << "\n";
            cout << "\t\t\tExperience: " << emp.experience << "\n";
            cout << "\t\t\tCourse: " << emp.course << "\n";
            cout << "\t\t\tRoles: " << emp.roles << "\n";
            cout << "\t\t\tWorking Hours: " << emp.working_hours << "\n";
        }

        if (total == 1) {
            cout << "\n\t\t\tNo Data is Present..." << endl;
        }
    }

    file.close();
}


void employee_modify(Employee emp) {

{
    system("cls");
    fstream file, file1;
    int employeeID;
    int found = 0;

    cout << "\n-------------------------------------------------------------------------------------------------------" << endl;
    cout << "------------------------------------- Employee Modify Details ----------------------------------------" << endl;

    file.open("employeeRecord.txt", ios::in);
    if (!file)
    {
        cout << "\n\t\t\tNo Data is Present..";
        file.close();
    }
    else
    {
        cout << "\nEnter Employee ID which you want to Modify: ";
        cin >> employeeID;
        file1.open("temp.txt", ios::app | ios::out);

        while (file >> emp.employee_ID >> emp.Fname >> emp.Lname >> emp.age >> emp.gender >> emp.phone_number >> emp.email >> emp.employment_history >> emp.qualifications >> emp.experience >> emp.course >> emp.roles >> emp.working_hours)
        {
            if (employeeID != emp.employee_ID)
            {
                file1 << " " << emp.employee_ID << " " << emp.Fname << " " << emp.Lname << " " << emp.age << " " << emp.gender << " " << emp.phone_number << " " << emp.email << " " << emp.employment_history << " " << emp.qualifications << " " << emp.experience << " " << emp.course << " " << emp.roles << " " << emp.working_hours << "\n";
            }
            else
            {
                cout << "\n-------------------------------------------------------------------------------------------------------" << endl;
                cout << "------------------------------------- Modify Employee Details ----------------------------------------" << endl;
                cout << "\t\t\tEnter First Name: ";
                cin >> emp.Fname;
                cout << "\t\t\tEnter Last Name: ";
                cin >> emp.Lname;
                cout << "\t\t\tEnter Age: ";
                cin >> emp.age;
                cout << "\t\t\tEnter Gender: ";
                cin >> emp.gender;
                cout << "\t\t\tEnter Phone Number: ";
                cin >> emp.phone_number;
                cout << "\t\t\tEnter Email: ";
                cin >> emp.email;
                cout << "\t\t\tEnter Employment History: ";
                cin >> emp.employment_history;
                cout << "\t\t\tEnter Qualifications: ";
                cin >> emp.qualifications;
                cout << "\t\t\tEnter Experience: ";
                cin >> emp.experience;
                cout << "\t\t\tEnter Course: ";
                cin >> emp.course;
                cout << "\t\t\tEnter Roles: ";
                cin >> emp.roles;
                cout << "\t\t\tEnter Working Hours: ";
                cin >> emp.working_hours;

                file1 << " " << emp.employee_ID << " " << emp.Fname << " " << emp.Lname << " " << emp.age << " " << emp.gender << " " << emp.phone_number << " " << emp.email << " " << emp.employment_history << " " << emp.qualifications << " " << emp.experience << " " << emp.course << " " << emp.roles << " " << emp.working_hours << "\n";
                found++;
            }
        }

        file.close();
        file1.close();

        if (found == 0)
        {
            cout << "\n\n\t\t\t Employee ID Not Found....";
        }

        remove("employeeRecord.txt");
        rename("temp.txt", "employeeRecord.txt");
    }
}
}


void employee_search(Employee &emp) {
    system("cls");
    fstream file;
    file.open("employeeRecord.txt", ios::in);

    if (!file) {
        cout << "\n-------------------------------------------------------------------------------------------------------" << endl;
        cout << "------------------------------------- Employee Search Data --------------------------------------------" << endl;
        cout << "\n\t\t\tNo Data is Present... " << endl;
    } else {
        int found = 0;
        int employeeID;

        cout << "\n-------------------------------------------------------------------------------------------------------" << endl;
        cout << "------------------------------------- Employee Search Table --------------------------------------------" << endl;
        cout << "\nEnter Employee ID of Employee you want to search: ";
        cin >> employeeID;

        while (file >> emp.employee_ID >> emp.Fname >> emp.Lname >> emp.age >> emp.gender >> emp.phone_number >> emp.email >> emp.employment_history >> emp.qualifications >> emp.experience >> emp.course >> emp.roles >> emp.working_hours) {
            if (employeeID == emp.employee_ID) {
                cout << "\n\t\t\tEmployee ID: " << emp.employee_ID << "\n";
                cout << "\t\t\tFirst Name: " << emp.Fname << "\n";
                cout << "\t\t\tLast Name: " << emp.Lname << "\n";
                cout << "\t\t\tAge: " << emp.age << "\n";
                cout << "\t\t\tGender: " << emp.gender << "\n";
                cout << "\t\t\tPhone Number: " << emp.phone_number << "\n";
                cout << "\t\t\tEmail: " << emp.email << "\n";
                cout << "\t\t\tEmployment History: " << emp.employment_history << "\n";
                cout << "\t\t\tQualifications: " << emp.qualifications << "\n";
                cout << "\t\t\tExperience: " << emp.experience << "\n";
                cout << "\t\t\tCourse: " << emp.course << "\n";
                cout << "\t\t\tRoles: " << emp.roles << "\n";
                cout << "\t\t\tWorking Hours: " << emp.working_hours << "\n";
                found++;
            }
        }

        if (found == 0) {
            cout << "\n\t\t\t Employee ID Not Found....";
        }

        file.close();
    }
}

void delete_employee(Employee emp)
    {
        int ID, count = 0;
    cout << "DELETE TEACHER" << endl;
    cout << "Enter Teacher's ID you want to delete: ";
    cin >> ID;

    fstream File;
    File.open("employeeRecord.txt", ios::in);
    ofstream tempfile;
    tempfile.open("temporary.txt", ios::out);

   while (File >> emp.employee_ID >> emp.Fname >> emp.Lname >> emp.age >> emp.gender >> emp.phone_number >> emp.email >> emp.experience >> emp.employment_history >> emp.qualifications >> emp.course >> emp.roles) {
    if (emp.employee_ID != ID) {
        tempfile << emp.employee_ID << " " << emp.Fname << " " << emp.Lname << " " << emp.age << " " << emp.gender << " " << emp.phone_number << " " << emp.email << " " << emp.experience << " " << emp.employment_history << " " << emp.qualifications << " " << emp.course << " " << emp.roles << endl;
    } else {
        count++;
    }

    File.close();
    tempfile.close();
    remove("employeeRecord.txt");
    rename("temporary.txt", "employeeRecord.txt");

    if (count == 0) {
       cout << "Employee record not found!" << endl;

    } else
        cout << "Employee record deleted successfully!" << endl;
}
    }
//Deleting Employee Data Function

void Employee_delete(Employee emp) {
system("cls");
    fstream file, file1;
    int found = false;
    int id;

    cout << "\n-------------------------------------------------------------------------------------------------------" << endl;
    cout << "------------------------------------- Delete Employee Details ------------------------------------------" << endl;

    file.open("teachers.txt", ios::in);

    if (!file) {
        cout << "\n\t\t\tNo Data is Present..";
        file.close();
    } else {
        cout << "\nEnter Employee ID of Employee whose data you want to Delete: ";
        cin >> id;

        file1.open("record.txt", ios::app | ios::out);

        while (file >> emp.employee_ID >> emp.Fname >> emp.Lname >> emp.age >> emp.gender >> emp.phone_number >> emp.email >> emp.employment_history >> emp.qualifications
               >> emp.experience >> emp.course >> emp.roles >> emp.working_hours) {
            if (id != emp.employee_ID) {
                file1 << " " << emp.employee_ID << " " << emp.Fname << " " << emp.Lname << " " << emp.age << " " << emp.gender << " " << emp.phone_number
                    << " " << emp.email << " " << emp.employment_history << " " << emp.qualifications << " " << emp.experience << " " << emp.course << " "
                    << emp.roles << " " << emp.working_hours << "\n";
            } else {
                found = true;;
                cout << "\n\t\t\tSuccessfully Delete Data";
            }
        }

        if (!found) {
            cout << "\n\t\t\t Employee ID Not Found....";
        }

        file1.close();
        file.close();

        remove("employeeRecord.txt");
        rename("record.txt", "employeeRecord.txt");
    }
}

double calculate_salary(Employee &emp) {
    int ID;
    cout << "Enter the employee ID: ";
    cin >> ID;
    int hoursWorked;
    int weeklyHours;
    cout << "Enter working hours weekly: ";
    cin >> weeklyHours;
    emp.working_hours = 4 * weeklyHours;
    int totalWorked = 0; // Initialize totalWorked to 0

    for (int i = 0; i < 4; i++) {
        cout << "How many hours did you work in week " << i + 1 << "? ";
        cin >> hoursWorked;
        totalWorked += hoursWorked; // Accumulate total worked hours
    }

    double paymentPerHour = 500.0;
    double salary = paymentPerHour * totalWorked;
    cout << "The salary of " << emp.Fname << " " << emp.Lname << " is: " << salary << " birr" << endl;
    return salary; // Return the calculated salary
}

void evaluate_performance(Employee &emp) {
    int ID;
    cout << "Enter the employee ID: ";
    cin >> ID;
    int hoursWorked;
    int weeklyHours;
    cout << "Enter working hours weekly: ";
    cin >> weeklyHours;
    emp.working_hours = 4 * weeklyHours;
    int totalWorked = 0; // Initialize totalWorked to 0

    for (int i = 0; i < 4; i++) {
        cout << "How many hours did you work in week " << i + 1 << "? ";
        cin >> hoursWorked;
        totalWorked += hoursWorked; // Accumulate total worked hours
    }

    if (totalWorked == emp.working_hours) {
        cout << "Excellent performance\n";
    } else if (totalWorked >= (0.75 * emp.working_hours)) {
        cout << "Good performance\n";
    } else if (totalWorked >= (0.50 * emp.working_hours)) {
        cout << "Bad performance\n";
    } else if (totalWorked >= 0) {
        cout << "Very bad performance\n";
    } else {
        cout << "Invalid input\n";
    }
}


void menu() {
    int choice;

    do {
        char x;
        system("cls");
        cout << "\t\t\t 1. Enter New Employee Record" << endl;
        cout << "\t\t\t 2. Display Employee Records" << endl;
        cout << "\t\t\t 3. Update Employee Record" << endl;
        cout << "\t\t\t 4. Search Employee Record" << endl;
         cout << "\t\t\t 5. calculate Employee Record" << endl;
         cout << "\t\t\t 6. evaluation Employee Record" << endl;
        cout << "\t\t\t 8. Exit" << endl;
        cout << "\n Enter Your Choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                do {
                    Employee emp;
                    employee_insert(emp);
                    cout << "Do you want to add another employee record? (y/n): ";
                    cin >> x;
                } while (x == 'y' || x == 'Y');
                break;
            case 2:
                {
                    Employee emp;
                    employee_display(emp);
                    break;
                }
            case 3:
                {
                    Employee emp;
                    employee_modify(emp);
                    break;
                }
            case 4:
                {
                    Employee emp;
                    employee_search(emp);
                    break;
                }

            case 5:
                {
                    Employee emp;
                    calculate_salary(emp);
                    break;
                }
            case 6:
                {
                   Employee emp;
                   evaluate_performance(emp);
                   break;
                }
            case 8:
                cout << "\n\t\t\t Program Is Exiting..." << endl;
                exit(0);
                break;
            default:
                cout << "\n\t\t\t Invalid Choice... Please Try Again..." << endl;
        }

        getch();
    } while (choice != 0);
}

int main() {
    menu();
    return 0;
}
