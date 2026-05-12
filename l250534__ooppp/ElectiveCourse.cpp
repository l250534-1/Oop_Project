#include "ElectiveCourse.h"
using namespace std;

ElectiveCourse::ElectiveCourse(string courseId, string title, string teacherId)
    : Course(courseId, title, teacherId, "Elective")
{}

double ElectiveCourse::calculateFinalGrade(string studentId)
{
    double total = 0;
    for (int i = 0; i < assessmentCount; i++)
    {
        if (assessments[i]->getStudentId() == studentId)
        {
            total += assessments[i]->calculateWeightedScore();
        }
    }

    return total;
}

int ElectiveCourse::getExamDuration() { 
    return 2;
}
