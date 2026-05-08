#pragma once
#include "Assessment.h"

class Exam : public Assessment {
public:
    Exam(double rawScore, double maxScore, double weightage);
    double calculateWeightedScore();
    void   display();
};