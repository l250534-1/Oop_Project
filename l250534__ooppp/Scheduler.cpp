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

}
void Scheduler::addSection(Section s)
{

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
