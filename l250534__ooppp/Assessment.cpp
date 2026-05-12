#include "Assessment.h"
#include <iostream>
using namespace std;

Assessment::Assessment(string studentId, string type, double rawScore, double maxScore, double weightage)
{
    this->studentId = studentId;
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
string Assessment::getStudentId()
{
    return studentId;
}
Assessment::~Assessment() {}
