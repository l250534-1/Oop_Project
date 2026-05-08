
#pragma once
#include <string>
using namespace std;

class AcademicEntity {

protected:
    string id;
    string name;
    string email;

public:
    AcademicEntity(string id, string name, string email);
    virtual void displayProfile() = 0;
    string getId();
    string getName();
    string getEmail();
    virtual ~AcademicEntity();
};


