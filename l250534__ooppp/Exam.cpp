#include "Exam.h"
#include <iostream>
using namespace std;

Exam::Exam(string studentId,double rawScore, double maxScore, double weightage)
    : Assessment(studentId, "Exam", rawScore, maxScore, weightage)
{
}

double Exam::calculateWeightedScore()
{
    return (rawScore / maxScore) * weightage;
}

void Exam::display() 
{
    cout << "  [Exam]" << rawScore << "/" << maxScore
        << "  Weighted: " << calculateWeightedScore() << "%" << endl;
}
