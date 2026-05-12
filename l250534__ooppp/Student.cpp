#include "Student.h"
#include <iostream>
using namespace std;

Student::Student(string id, string name, string email, string type)
    : AcademicEntity(id, name, email)
{
    this->type = type;
    enrolledCount = 0;
}

void Student::enrollinCourse(string courseId) {
    if (enrolledCount >= 20) 
    {
        cout << "  ERROR: Cannot enroll max 20 courses reached!" << endl;
        return;
    }
    enrolledCourse_ids[enrolledCount] = courseId;
    enrolledCount++;
}

bool Student::isEnrolledIn(string courseId)
{
    for (int i = 0; i < enrolledCount; i++)
    {
        if (enrolledCourse_ids[i] == courseId)
        {
            return true;
        }
    }
    return false;
}

string Student::getType()
{
    return type; 
}
int Student::getEnrolledCount() { 
    return enrolledCount;
}
string Student::getEnrolledCourse(int i) {
    return enrolledCourse_ids[i];
}
