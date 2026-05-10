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