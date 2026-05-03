#include "AcademicEntity.h"
#include <iostream>
using namespace std;

AcademicEntity::AcademicEntity(string id, string name, string email) {
    this->id = id;
    this->name = name;
    this->email = email;
}

string AcademicEntity::getId() { return id; }
string AcademicEntity::getName() { return name; }
string AcademicEntity::getEmail() { return email; }

AcademicEntity::~AcademicEntity() {}
