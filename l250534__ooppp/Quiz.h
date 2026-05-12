#pragma once


#include "Assessment.h"

class Quiz : public Assessment {
public:
    Quiz(string studentId, double rawScore, double maxScore, double weightage);
    double calculateWeightedScore();
    void   display();
};


