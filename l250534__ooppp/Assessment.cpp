#include "Assessment.h"
#include <iostream>
using namespace std;

Assessment::Assessment(string type, double rawScore, double maxScore, double weightage)
{
    this->type = type;
    this->rawScore = rawScore;
    this->maxScore = maxScore;
    this->weightage = weightage;
}

string Assessment::getType() {
    return type;
}
double Assessment::getRawScore() {
    return rawScore; 
}
double Assessment::getMaxScore() {
    return maxScore;
}
double Assessment::getWeightage() {
    return weightage;
}
Assessment::~Assessment() {}
