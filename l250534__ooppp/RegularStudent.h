#pragma once
#include "Student.h"
class RegularStudent : public Student {
private:
    double grades[20];//weighted points(GPA × credits)
    int gradeCount;
    double totalPoints;//Sum of all (GPA × credits)
    int totalCredits;
    string gradeCourses[20];//Course IDs for each grade

public:
    RegularStudent();
    RegularStudent(string id, string name, string email);
    
    double calculateGPA();//abstr
    void viewTranscript();//abstr
    void displayProfile();//abstr from acdmic entitty
    void addGrade(double points, int credits, string courseId);
 /*   void addGrade(double points, int credits);*/
};
