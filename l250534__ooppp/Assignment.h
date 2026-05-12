#pragma once

#include "Assessment.h"

class Assignment : public Assessment {
public:
    Assignment(string studentId, double rawScore, double maxScore, double weightage);
    double calculateWeightedScore();
    void   display();
};