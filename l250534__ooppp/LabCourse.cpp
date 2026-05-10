#include "LabCourse.h"
using namespace std;

LabCourse::LabCourse(string courseId, string title, string teacherId)
    : Course(courseId, title, teacherId, "Lab") {
    requiresComputers = true;
}

double LabCourse::calculateFinalGrade() {
    double total = 0;
    for (int i = 0; i < assessmentCount; i++) {
        if (assessments[i]->getType() != "Exam")
            total += assessments[i]->calculateWeightedScore();
    }
    return total;
}

int  LabCourse::getExamDuration() { return 0; }
bool LabCourse::getRequiresComputers() { return requiresComputers; }
