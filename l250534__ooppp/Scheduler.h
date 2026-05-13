#pragma once
#include "Section.h"
#include "Venue.h"
#include "Course.h"
#include "LabCourse.h"
#include <fstream>
using namespace std;
class Scheduler {
private:
    Section* sections[100];//aggregation
    int sectionCount;
    Venue venues[20];
    int venueCount;
    string timeSlots[20];
    int timeSlotCount;

public:
    Scheduler();
    void   addSection(Section *s);
    void   addVenue(Venue v);
    bool   isVenueBooked(string venueId, string timeSlot);
    string suggestNextSlot(string venueId);
    void   generateExamSchedule(Course* courses[], int courseCount);
    void   saveSchedule();
    void   displaySchedule();
};
