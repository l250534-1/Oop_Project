//Scholarship Student: Must maintain a minimum GPA; otherwise, their status flag changes to "Probation."
#include "ScholarshipStudent.h"
#include <iostream>
using namespace std;
//grade is Final % for course → convert → GPA → multiply by credits
ScholarshipStudent::ScholarshipStudent()
    : Student("", "", "", "Scholarship") 
{
    minGPA = 2.0;
    gradeCount = 0;
    status = "Active";
    totalPoints = 0;
    totalCredits = 0;
}

ScholarshipStudent::ScholarshipStudent(string id, string name, string email, double minGPA)
    : Student(id, name, email, "Scholarship") 
{
    this->minGPA = minGPA;
    gradeCount = 0;
    status = "Active";
    totalPoints = 0;
    totalCredits = 0;
}

void ScholarshipStudent::addGrade(double weightedPoints, int credits, string courseId)
{
    for (int i = 0; i < gradeCount; i++)
    {
        if (gradeCourses[i] == courseId)
        {
            totalPoints -= grades[i];
            grades[i] = weightedPoints;
            totalPoints += weightedPoints;

            checkStatus();   
            return;
        }
    }

    if (gradeCount < 20)
    {
        gradeCourses[gradeCount] = courseId;
        grades[gradeCount] = weightedPoints;
        gradeCount++;
        totalPoints += weightedPoints;
        totalCredits += credits;

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
    if (totalCredits == 0)
        return 0.0;

    return totalPoints / totalCredits;
}

void ScholarshipStudent::viewTranscript() 
{
    cout << endl;
    cout << "TRANSCRIPT: " << name << endl;
    cout  << endl;
    if (gradeCount == 0) 
    {
        cout << "No grades yet." << endl;
    }
    cout << "GPA     : " << calculateGPA() << endl;
    cout << "Status  : " << status << endl;
    if (status == "Probation") 
    {
        cout << "!! WARNING: GPA below minimum !!" << endl;
    }
    cout  << endl;
}

void ScholarshipStudent::displayProfile() {
    cout  << endl;
    cout << "SCHOLARSHIP STUDENT" << endl;
    cout  << endl;
    cout << "ID      : " << id << endl;
    cout << "Name    : " << name << endl;
    cout << "Email   : " << email << endl;
    cout << "GPA     : " << calculateGPA() << endl;
    cout << "Status  : " << status << endl;
    cout  << endl;
}

string ScholarshipStudent::getStatus() { 
    return status; 
}
double ScholarshipStudent::getMinGPA() {
    return minGPA;
}
