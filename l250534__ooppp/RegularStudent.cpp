#include "RegularStudent.h"
#include <iostream>
using namespace std;

RegularStudent::RegularStudent()
    : Student("", "", "", "Regular") 
{
    gradeCount = 0;
}

RegularStudent::RegularStudent(string id, string name, string email)
    : Student(id, name, email, "Regular") 
{
    gradeCount = 0;
}

void RegularStudent::addGrade(double grade) 
{
    if (gradeCount < 20) 
    {
        grades[gradeCount] = grade;
        gradeCount++;
    }
}

double RegularStudent::calculateGPA() 
{
    if (gradeCount == 0)
        return 0.0;
    double total = 0;
    for (int i = 0; i < gradeCount; i++) {
        total += grades[i];
    }
    return total / gradeCount;
}

void RegularStudent::viewTranscript() {
    cout  << endl;
    cout << "  TRANSCRIPT: " << name << endl;
    cout << endl;
    if (gradeCount == 0) {
        cout << "  No grades yet." << endl;
    }
    else {
        for (int i = 0; i < gradeCount; i++)
        {
            cout << "  Course " << (i + 1) << " : " << grades[i] << "%" << endl;
        }
    }
    cout << "  GPA     : " << calculateGPA() << endl;
    cout  << endl;
}

void RegularStudent::displayProfile() {
    cout << endl;
    cout << "     REGULAR STUDENT" << endl;
    cout<< endl;
    cout << "  ID    : " << id << endl;
    cout << "  Name  : " << name << endl;
    cout << "  Email : " << email << endl;
    cout << "  GPA   : " << calculateGPA() << endl;
    cout <<endl;
}
