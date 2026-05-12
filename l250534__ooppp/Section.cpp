//schedule class group of a course taught by a teacher that will take an exam in a venue at a scheduled

#include "Section.h"
#include <iostream>
using namespace std;

Section::Section() {
    sectionId = "";
    courseId = "";
    teacherId = "";
    venueId = "Unassigned";
    timeSlot = "Unassigned";
}

Section::Section(string sectionId, string courseId, string teacherId) {
    this->sectionId = sectionId;
    this->courseId = courseId;
    this->teacherId = teacherId;
    this->venueId = "Unassigned";
    this->timeSlot = "Unassigned";
}

bool Section::hasTimeConflict(string otherTimeSlot) 
{
    return timeSlot == otherTimeSlot;
}

void Section::assignVenue(string venueId, string timeSlot)
{
    this->venueId = venueId;
    this->timeSlot = timeSlot;
}

void Section::display() {
    cout << "Section  : " << sectionId << endl;
    cout << "Course   : " << courseId << endl;
    cout << "Teacher  : " << teacherId << endl;
    cout << "Venue    : " << venueId << endl;
    cout << "Time     : " << timeSlot << endl;
}

string Section::getSectionId() { 
    return sectionId;
}
string Section::getCourseId() {
    return courseId; 
}
string Section::getTeacherId() {
    return teacherId; 
}
string Section::getVenueId() {
    return venueId;
}
string Section::getTimeSlot() {
    return timeSlot;
}
