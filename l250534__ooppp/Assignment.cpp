#include "Assignment.h"
#include <iostream>
using namespace std;

Assignment::Assignment(string studentId,double rawScore, double maxScore, double weightage)
    : Assessment(studentId, "Assignment", rawScore, maxScore, weightage)
{}

double Assignment::calculateWeightedScore() {

    return (rawScore / maxScore) * weightage;
}

void Assignment::display() {
    cout << "  [Assignment] " << rawScore << "/" << maxScore
        << "  Weightage: " << calculateWeightedScore() << "%" << endl;
}
