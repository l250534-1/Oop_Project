#include "Scheduler.h"
#include <iostream>
#include <fstream>
using namespace std;

Scheduler::Scheduler()
{
	//timeslots
	sectionCount = 0;
	venueCount = 0;
	
	timeSlots[0] = "Mon 08:00-11:00";
	timeSlots[1] = "Mon 11:30-14:30";
	
	timeSlots[2] = "Mon 15:00-17:00";
	timeSlots[3] = "Mon 17:00-18:00";
	timeSlots[4] = "Tue 8:00-10:00";
	timeSlots[5] = "Tue 10:00-11:00";
	timeSlots[6] = "Tue 11:00-14:00";

	timeSlots[7] = "Tue 14:30-17:30";
	timeSlots[8] = "Wed 8:00-11:00";
	timeSlots[9] = "Wed 11:30-14:30";

	timeSlots[10] = "Wed 15:00-17:00";
	timeSlots[11] = "Wed 17:00-18:00";
	timeSlots[12] = "Thurs 8:00-10:00";
	timeSlots[13] = "Thurs 10:00-11:00";
	timeSlots[14] = "Thurs 11:00-14:00";
	timeSlots[15] = "Thurs 14:30-17:30";
	timeSlots[16] = "Fri    8:00-11:00";
	timeSlots[17] = "Fri    14:30-16:30";
	timeSlotCount = 17;

}
void Scheduler::addSection(Section s)
{
	if (sectionCount < 100) 
	{
		sections[sectionCount] = s;
		sectionCount++;
	}
}
void Scheduler::addVenue(Venue v) 
{

}

bool Scheduler::isVenueBooked(string venueId, string timeSlot)
{

}

string Scheduler::suggestNextSlot(string venueId)
{

}

void Scheduler::generateExamSchedule(Course* courses[], int courseCount)
{

}

void Scheduler::saveSchedule()
{

}

void Scheduler::displaySchedule() 
{
}
