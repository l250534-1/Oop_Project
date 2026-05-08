#include "Assignment.h"
#include <iostream>
using namespace std;

Assignment::Assignment(double rawScore, double maxScore, double weightage)
    : Assessment("Assignment", rawScore, maxScore, weightage) {
}

double Assignment::calculateWeightedScore() {
    return (rawScore / maxScore) * weightage;
}

void Assignment::display() {
    cout << "  [Assignment] " << rawScore << "/" << maxScore
        << "  Weighted: " << calculateWeightedScore() << "%" << endl;
}
