#include "Course.h"
#include <iostream>
using namespace std;

Course::Course(string courseId, string title, string teacherId, string type) {
    this->courseId = courseId;
    this->title = title;
    this->teacherId = teacherId;
    this->type = type;
    studentCount = 0;
    assessmentCount = 0;
}

bool Course::enrollStudent(string studentId)
{
    if (studentCount >= 60) 
    {
        cout << "  ERROR: Course is full! (max 60)" << endl;
        return false;
    }
    if (isStudentEnrolled(studentId))
    {
        cout << "  ERROR: Student already enrolled!" << endl;
        return false;
    }
    enrolledStudentIds[studentCount] = studentId;
    studentCount++;
    return true;
}

bool Course::isStudentEnrolled(string studentId) 
{
    for (int i = 0; i < studentCount; i++) 
    {
        if (enrolledStudentIds[i] == studentId) return true;
    }
    return false;
}

void Course::addAssessment(Assessment* a) 
{
    if (assessmentCount < 10) {
        assessments[assessmentCount] = a;
        assessmentCount++;
    }
}

void Course::displayAssessments()
{
    cout << " \t\tAssessments for " << title << "\t\t" << endl;
    if (assessmentCount == 0) {
        cout << "  No assessments yet." << endl;
        return;
    }
    for (int i = 0; i < assessmentCount; i++) {
        assessments[i]->display();
    }
}

string Course::getCourseId()
{ 
    return courseId;
}
string Course::getTitle() {
    return title; 
}
string Course::getTeacherId() { 
    return teacherId; 
}
string Course::getCourseType() { 
    return type; 
}
int    Course::getStudentCount() {
    return studentCount; 
}

Course::~Course() {
    for (int i = 0; i < assessmentCount; i++) {
        delete assessments[i];
    }
}
