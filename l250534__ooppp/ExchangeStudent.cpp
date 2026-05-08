#include "ExchangeStudent.h"
#include <iostream>
using namespace std;

ExchangeStudent::ExchangeStudent()
    : Student("", "", "", "Exchange") 
{
    resultCount = 0;
}

ExchangeStudent::ExchangeStudent(string id, string name, string email)
    : Student(id, name, email, "Exchange") 
{
    resultCount = 0;
}

void ExchangeStudent::addResult(string passFail) 
{
    if (resultCount < 20)
    {
        results[resultCount] = passFail;
        resultCount++;
    }
}

double ExchangeStudent::calculateGPA() 
{ 
    return 0.0;
}

void ExchangeStudent::viewTranscript() {
    cout <<  endl;
    cout << "  TRANSCRIPT: " << name << endl;
    cout << "  (Exchange : Pass/Fail only)" << endl;
    cout << endl;
    if (resultCount == 0) 
    {
        cout << "  No results yet." << endl;
    }
    else {
        for (int i = 0; i < resultCount; i++) 
        {
            cout << "  Course " << (i + 1) << " : " << results[i] << endl;
        }
    }
    cout << endl;
}

void ExchangeStudent::displayProfile() {
    cout  << endl;
    cout << "     EXCHANGE STUDENT" << endl;
    cout  << endl;
    cout << "  ID    : " << id << endl;
    cout << "  Name  : " << name << endl;
    cout << "  Email : " << email << endl;
    cout << "  Type  : Exchange (Pass/Fail only)" << endl;
    cout  << endl;
}
