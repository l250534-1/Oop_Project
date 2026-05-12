#pragma once
#include "Assessment.h"

class Course {

protected:
    string courseId;
    string title;
    string teacherId;
    string type;
    string enrolledStudentIds[60];
    int    studentCount;
    Assessment* assessments[10];
    int    assessmentCount;

public:
    Course(string courseId, string title, string teacherId, string type);
    virtual double calculateFinalGrade(string studentId) = 0;
    virtual int    getExamDuration() = 0;
    bool   enrollStudent(string studentId);
    bool   isStudentEnrolled(string studentId);
    void   addAssessment(Assessment* a);
    void displayAssessments(string studentId);
    string getCourseId();
    string getTitle();
    string getTeacherId();
    string getCourseType();
    int    getStudentCount();
    virtual ~Course();
};

