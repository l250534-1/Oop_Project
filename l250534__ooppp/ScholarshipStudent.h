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

public:
    ScholarshipStudent();
    ScholarshipStudent(string id, string name, string email, double minGPA);
    void   addGrade(double grade,int credits);
    void   checkStatus();
    double calculateGPA();
    void   viewTranscript();
    void   displayProfile();
    string getStatus();
    double getMinGPA();
};

