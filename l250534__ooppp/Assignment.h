#pragma once

#include "Assessment.h"

class Assignment : public Assessment {
public:
    Assignment(double rawScore, double maxScore, double weightage);
    double calculateWeightedScore();
    void   display();
};