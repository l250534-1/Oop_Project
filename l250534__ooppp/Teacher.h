

#pragma once

#include "academicEntity.h"
#include <string>          
using namespace std;

class Teacher : public AcademicEntity {

private:
    //max student=150, feedbacks from each student
    double feedbackScores[150];
    int feedbackCount;
    string assignedCourseIds[20];
    int courseCount;

public:
    Teacher();
    Teacher(string id, string name, string email);
    void displayProfile();
    void addFeedback(int rating);
    double getAverageScore();
    void assignCourse(string courseId);
    int getCourseCount();
    string getAssignedCourse(int index);
};


