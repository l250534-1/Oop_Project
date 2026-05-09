#include "CoreCourse.h"
using namespace std;

CoreCourse::CoreCourse(string courseId, string title, string teacherId)
    : Course(courseId, title, teacherId, "Core") {
}

double CoreCourse::calculateFinalGrade() {
    double total = 0;
    for (int i = 0; i < assessmentCount; i++)
        total += assessments[i]->calculateWeightedScore();//declared in assssment.h(abstract)
    return total;
}

int CoreCourse::getExamDuration() {
    return 3;
}