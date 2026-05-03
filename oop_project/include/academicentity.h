
#ifndef ACADEMICENTITY_H
#define ACADEMICENTITY_H

#include <string>
using namespace std;

class AcademicEntity {

protected:
    string id;
    string name;
    string email;

public:
    AcademicEntity(string id, string name, string email);
    virtual void displayProfile() = 0;//abstarct
    string getId();
    string getName();
    string getEmail();
    virtual ~AcademicEntity();
};

#endif
