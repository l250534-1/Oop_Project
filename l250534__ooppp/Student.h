#pragma once
#include "academicEntity.h"

class Student : public AcademicEntity {

protected:
    string enrolledCourse_ids[20];
    int    enrolledCount;
    string type;

public:
    Student(string id, string name, string email, string type);
    virtual double calculateGPA() = 0;
    virtual void   viewTranscript() = 0;
    virtual void   displayProfile() = 0;
    void   enrollinCourse(string courseId);
    bool   isEnrolledIn(string courseId);
    string getType();
    int    getEnrolledCount();
    string getEnrolledCourse(int index);
};
