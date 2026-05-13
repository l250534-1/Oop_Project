// Regular Student : The standard data model with traditional grading.

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
    totalPoints = 0;
    totalCredits = 0;
}

//void RegularStudent::addGrade(double weightedpoints,int credits) 
//{
//    if (gradeCount < 20)
//    {
//        grades[gradeCount] = weightedpoints;
//        gradeCount++;
//        totalPoints += weightedpoints;
//        totalCredits += credits;
//    }
//    else
//        cout << "20 courses enrolled" << endl;
//}



void RegularStudent::viewTranscript() {
    cout  << endl;
    cout << "TRANSCRIPT: " << name << endl;
    cout << endl;
    if (gradeCount == 0)
    {
    cout << "No grades yet." << endl;
    }
  
    cout << "  GPA     : " << calculateGPA() << endl;
    cout  << endl;
}

double RegularStudent::calculateGPA()
{
    if (totalCredits == 0)
        return 0.0;

    return totalPoints / totalCredits;
}

void RegularStudent::displayProfile() {
    cout << endl;
    cout << "REGULAR STUDENT" << endl;
    cout<< endl;
    cout << "ID    : " << id << endl;
    cout << "Name  : " << name << endl;
    cout << "Email : " << email << endl;
    cout << "GPA   : " << calculateGPA() << endl;
    cout <<endl;
}

void RegularStudent::addGrade(double weightedPoints, int credits, string courseId)
{
   
    for (int i = 0; i < gradeCount; i++)
    {
        if (gradeCourses[i] == courseId)
        {
            totalPoints -= grades[i];      
            grades[i] = weightedPoints;  
            totalPoints += weightedPoints;  
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
    }
}