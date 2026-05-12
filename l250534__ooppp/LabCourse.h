#pragma once
#include "Course.h"


class LabCourse : public Course {
private:
    bool requiresComputers;
public:
    LabCourse(string courseId, string title, string teacherId);
    double calculateFinalGrade(string studentId);
    int    getExamDuration();
    bool   getRequiresComputers();
};
