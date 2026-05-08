#pragma once


#include "Student.h"

class ExchangeStudent : public Student {

private:
    string results[20];
    int    resultCount;

public:
    ExchangeStudent();
    ExchangeStudent(string id, string name, string email);
    void   addResult(string passFail);
    double calculateGPA();
    void   viewTranscript();
    void   displayProfile();
};


