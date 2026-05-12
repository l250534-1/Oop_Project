#pragma once

#include "Student.h"

class RegularStudent : public Student {

private:
    double grades[20];
    int    gradeCount;
    double totalPoints;
    int totalCredits;

public:
    RegularStudent();
    RegularStudent(string id, string name, string email);
    void addGrade(double points, int credits);
    double calculateGPA();
    void viewTranscript();
    void displayProfile();
};
