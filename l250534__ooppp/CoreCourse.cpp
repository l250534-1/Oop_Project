#include "CoreCourse.h"
using namespace std;

CoreCourse::CoreCourse(string courseId, string title, string teacherId)
    : Course(courseId, title, teacherId, "Core") {
}

double CoreCourse::calculateFinalGrade(string studentId) {
    double total = 0;
    for (int i = 0; i < assessmentCount; i++)

        if (assessments[i]->getStudentId() == studentId)
        {
            total += assessments[i]->calculateWeightedScore();
        }
    return total;
}

int CoreCourse::getExamDuration() {
    return 3;
}