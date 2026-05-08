#pragma once

#include "Student.h"

class RegularStudent : public Student {

private:
    double grades[20];
    int    gradeCount;

public:
    RegularStudent();
    RegularStudent(string id, string name, string email);
    void   addGrade(double grade);
    double calculateGPA();
    void   viewTranscript();
    void   displayProfile();
};
