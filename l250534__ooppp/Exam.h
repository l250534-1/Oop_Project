#pragma once
#include "Assessment.h"

class Exam : public Assessment {
public:
    Exam(string studentId, double rawScore, double maxScore, double weightage);
    double calculateWeightedScore();
    void   display();
};