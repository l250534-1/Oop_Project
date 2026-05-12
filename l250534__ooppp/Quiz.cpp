#include "Quiz.h"
#include <iostream>
using namespace std;

Quiz::Quiz(string studentId,double rawScore, double maxScore, double weightage)
    : Assessment (studentId, "Quiz", rawScore, maxScore, weightage) {
}

double Quiz::calculateWeightedScore() {
    return (rawScore / maxScore) * weightage;
}

void Quiz::display() {
    cout << "  Quiz       " << rawScore << "/" << maxScore
        << "  Weighted: " << calculateWeightedScore() << "%" << endl;
}
