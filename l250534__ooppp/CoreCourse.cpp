#include "CoreCourse.h"
#include <iostream> 
using namespace std;

CoreCourse::CoreCourse(string courseId, string title, string teacherId)
    : Course(courseId, title, teacherId, "Core") {
}

double CoreCourse::calculateFinalGrade(string studentId) 
{
    double total = 0;
   /* cout<< "DEBUG: assessmentCount=" << assessmentCount << endl;*/
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