#pragma once
#include "Course.h"


class ElectiveCourse : public Course {
public:
    ElectiveCourse(string courseId, string title, string teacherId);
    double calculateFinalGrade(string studentId);
    int    getExamDuration();
};
