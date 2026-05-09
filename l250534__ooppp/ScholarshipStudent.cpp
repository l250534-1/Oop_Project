//Scholarship Student: Must maintain a minimum GPA; otherwise, their status flag changes to "Probation."
#include "ScholarshipStudent.h"
#include <iostream>
using namespace std;

ScholarshipStudent::ScholarshipStudent()
    : Student("", "", "", "Scholarship") 
{
    minGPA = 2.0;
    gradeCount = 0;
    status = "Active";
}

ScholarshipStudent::ScholarshipStudent(string id, string name, string email, double minGPA)
    : Student(id, name, email, "Scholarship") 
{
    this->minGPA = minGPA;
    gradeCount = 0;
    status = "Active";
}

void ScholarshipStudent::addGrade(double grade) 
{
    if (gradeCount < 20)
    {
        grades[gradeCount] = grade;
        gradeCount++;
        checkStatus();
    }
}

void ScholarshipStudent::checkStatus()
{
    if (calculateGPA() < minGPA)
        status = "Probation";
    else
        status = "Active";
}

double ScholarshipStudent::calculateGPA() 
{
    if (gradeCount == 0) return 0.0;
    double total = 0;
    for (int i = 0; i < gradeCount; i++) total += grades[i];
    return total / gradeCount;
}

void ScholarshipStudent::viewTranscript() {
    cout << endl;
    cout << "  TRANSCRIPT: " << name << endl;
    cout  << endl;
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
    cout << "  Min GPA : " << minGPA << endl;
    cout << "  Status  : " << status << endl;
    if (status == "Probation") {
        cout << "  !! WARNING: GPA below minimum !!" << endl;
    }
    cout  << endl;
}

void ScholarshipStudent::displayProfile() {
    cout  << endl;
    cout << "   SCHOLARSHIP STUDENT" << endl;
    cout  << endl;
    cout << "  ID      : " << id << endl;
    cout << "  Name    : " << name << endl;
    cout << "  Email   : " << email << endl;
    cout << "  GPA     : " << calculateGPA() << endl;
    cout << "  Min GPA : " << minGPA << endl;
    cout << "  Status  : " << status << endl;
    cout  << endl;
}

string ScholarshipStudent::getStatus() { return status; 
}
double ScholarshipStudent::getMinGPA() { return minGPA;
}
