#pragma once
#include <string>
using namespace std;

class Section {
private:
    string sectionId;
    string courseId;
    string teacherId;
    string venueId;
    string timeSlot;

public:
    Section();
    Section(string sectionId, string courseId, string teacherId);
    bool   hasTimeConflict(string otherTimeSlot);
    void   assignVenue(string venueId, string timeSlot);
    void   display();
    string getSectionId();
    string getCourseId();
    string getTeacherId();
    string getVenueId();
    string getTimeSlot();
};

