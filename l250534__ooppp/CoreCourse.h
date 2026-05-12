#pragma once
#include "Course.h"


class CoreCourse : public Course {
public:
    CoreCourse(string courseId, string title, string teacherId);
    double calculateFinalGrade(string studentId);
    int    getExamDuration();
};
