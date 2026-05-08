#pragma once
#ifndef QUIZ_H
#define QUIZ_H

#include "Assessment.h"

class Quiz : public Assessment {
public:
    Quiz(double rawScore, double maxScore, double weightage);
    double calculateWeightedScore();
    void   display();
};

#endif

