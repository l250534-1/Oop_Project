#pragma once
#include "Student.h"

class ScholarshipStudent : public Student {

private:
    double grades[20];
    int    gradeCount;
    double minGPA;
    string status;
    double totalPoints;
    int totalCredits;
    string gradeCourses[20];

public:
    ScholarshipStudent();
    ScholarshipStudent(string id, string name, string email, double minGPA);
    void addGrade(double points, int credits, string courseId);

    void   checkStatus();
    double calculateGPA();
    void   viewTranscript();
    void   displayProfile();
    string getStatus();
    double getMinGPA();
};

