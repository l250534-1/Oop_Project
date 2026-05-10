#include "Menu.h"
#include <iostream>
using namespace std;

Menu::Menu() 
{
    teacherCount = 0;
    regularCount = 0;
    scholarshipCount = 0;
    exchangeCount = 0;
    courseCount = 0;
    venueCount = 0;
    sectionCount = 0;

    db.loadTeachers(teachers, teacherCount);
    db.loadVenues(venues, venueCount);
    db.loadSections(sections, sectionCount);

    for (int i = 0; i < venueCount; i++)
        scheduler.addVenue(venues[i]);
    for (int i = 0; i < sectionCount; i++)
        scheduler.addSection(sections[i]);
}
Menu::~Menu() {
    for (int i = 0; i < courseCount; i++)
        delete courses[i];
}
int Menu::getIntInput(string p) {
    int value;
    while (true) {
        cout << p;
        if (cin >> value) 
        {
            cin.ignore();
            return value;
        }
        cout << "  ERROR: Please enter a valid number!" << endl;
        cin.clear();
        cin.ignore();
    }
}
double Menu::getDoubleInput(string p) {
    double value;
    while (true)
    {
        cout << p;
        if (cin >> value)
        {
            cin.ignore();
            return value;
        }
        cout << "ERROR: Please enter a valid number!" << endl;
        cin.clear();
        cin.ignore();
    }
}
string Menu::getStringInput(string p) {
    string value;
    while (true) {
        cout << p;
        getline(cin, value);
        if (!value.empty()) 
            return value;
        cout << "ERROR: Input cannot be empty!" << endl;
    }
}
bool Menu::isIdUnique(string id)
{
    for (int i = 0; i < teacherCount; i++)
        if (teachers[i].getId() == id) 
            return false;
    for (int i = 0; i < regularCount; i++)
        if (regularStudents[i].getId() == id) 
            return false;
    for (int i = 0; i < scholarshipCount; i++)
        if (scholarshipStudents[i].getId() == id)
            return false;
    for (int i = 0; i < exchangeCount; i++)
        if (exchangeStudents[i].getId() == id) 
            return false;
    return true;
}

bool Menu::isRoomIdUnique(string roomId) {
    for (int i = 0; i < venueCount; i++)
        if (venues[i].getRoomId() == roomId) return false;
    return true;
}

Teacher* Menu::findTeacher(string id)
{
    for (int i = 0; i < teacherCount; i++)
        if (teachers[i].getId() == id)
            return &teachers[i];
    return nullptr;
}

Course* Menu::findCourse(string id) {
    for (int i = 0; i < courseCount; i++)
        if (courses[i]->getCourseId() == id) 
            return courses[i];
    return nullptr;
}
RegularStudent* Menu::findRegular(string id) 
{
    for (int i = 0; i < regularCount; i++)
        if (regularStudents[i].getId() == id) 
            return &regularStudents[i];
    return nullptr;
}

ScholarshipStudent* Menu::findScholarship(string id)
{
    for (int i = 0; i < scholarshipCount; i++)
        if (scholarshipStudents[i].getId() == id) 
            return &scholarshipStudents[i];
    return nullptr;
}

ExchangeStudent* Menu::findExchange(string id)
{
    for (int i = 0; i < exchangeCount; i++)
        if (exchangeStudents[i].getId() == id) 
            return &exchangeStudents[i];
    return nullptr;
}
