/**
 * Laboratory #7 - CSCI2421 - Summer 2021
 * File: main.cpp
 */

#include "iostream"
#include "memory"
#include "domain/StudentDatabase.h"

using namespace std;


/**********************************************************************************************************************/
int displayMenu(){
    int option=0;
    cout<<endl<<endl;
    cout << "-----------------------------------------------------------------------------" << endl;
    cout << "                              DATABASE MAIN MENU                             " << endl;
    cout << "-----------------------------------------------------------------------------" << endl;
    cout << "      1) List Students" << endl;
    cout << "      2) List Courses" << endl;
    cout << "      3) List Raw Records   " << endl;
    cout << "      4) List Students, Their Courses and Grades " << endl;
    cout << "                                         99) Quit" << endl;
    cout << "-----------------------------------------------------------------------------" << endl;
    while (option < 1 || option >4){
        cout << "      Select your option [1-4 / 99]>> ";
        cin >> option;
        if (option == 99)
            return -1;
    }
    return option;

}

/**********************************************************************************************************************/
int main(){
    cout << string(120, '=')  << endl;
    cout << string(50, ' ')<< "LABORATORY #7"  << endl;
    cout << string(20, ' ')<< "This lab will simulate a Database using Dictionaries to represent tables."  << endl;
    cout << string(120, '=')  << endl;


    auto database = make_shared<StudentDatabase>();
    database -> loadSampleDatabase();

    int option = 0;
    string searchMovie;
    string pattern;
    while (option>=0){
        option = displayMenu();
        switch (option) {
            case 1: // Display Students
                database->displayStudents();
                break;
            case 2: // Display Courses
                database->displayCourses();
                break;
            case 3: // Display Raw Records
                database->displayRecords();
                break;

            case 4: // Display Full Transcript
                database->displayTranscript();
                break;
            default:
                cout<< "Invalid option... Try again";
                break;
        }
    }
    cout << "Program Terminated." << endl;
    return 0;
}
