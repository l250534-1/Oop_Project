#include "Teacher.h"
#include <iostream>
using namespace std;

Teacher::Teacher() : AcademicEntity("", "", "") {
    feedbackCount = 0;
    courseCount = 0;
    for (int i = 0; i < 100; i++) {
        feedbackScores[i] = 0;    
    }
}

Teacher::Teacher(string id, string name, string email)
    : AcademicEntity(id, name, email) {
    feedbackCount = 0;
    courseCount = 0;
}

void Teacher::displayProfile() {
    cout << "\t\t\t" << endl;
    cout << "\t\tTEACHER PROFILE\t\t" << endl;
    cout  << endl;
    cout << "ID       : " << id << endl;
    cout << "Name     : " << name << endl;
    cout << "Email    : " << email << endl;
    cout << "Avg Score: " << getAverageScore() << "/5" << endl;
    cout << "Courses  : " << courseCount << endl;
    cout <<  endl;
}

void Teacher::addFeedback(int rating) 
{
    if (feedbackCount < 100) 
    {
        feedbackScores[feedbackCount] = rating;
        feedbackCount++;
    }
}

double Teacher::getAverageScore()
{
    if (feedbackCount == 0) {
        return 0.0;
    }
    double total = 0;
    for (int i = 0; i < feedbackCount; i++) 
    {
        total += feedbackScores[i];
    }
    return total / feedbackCount;
}

void Teacher::assignCourse(string courseId)
{
    if (courseCount < 20)
    {
        assignedCourseIds[courseCount] = courseId;
        courseCount++;
    }
}

int    Teacher::getCourseCount() 
{
    return courseCount; 
}
string Teacher::getAssignedCourse(int i)
{
    return assignedCourseIds[i]; 
}
