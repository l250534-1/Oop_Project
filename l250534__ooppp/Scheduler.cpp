//This Scheduler class is basically an exam scheduling engine.
// Its job is to take sections + venues + courses 
// and assign each section a room and time slot without conflicts.
//section venue time slot (arrays)
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
	timeSlotCount = 18;
}

void Scheduler::addSection(Section* s)
{
	if (sectionCount < 100)
	{
		sections[sectionCount] = s;
		sectionCount++;
	}
}
void Scheduler::addVenue(Venue v) 
{
	if (venueCount < 20) {
		venues[venueCount] = v;
		venueCount++;
	}
}

//Does this section already use the same room AND the same time
bool Scheduler::isVenueBooked(string venueId, string timeSlot)
{
	for (int i = 0; i < sectionCount; i++)
	{
		if (sections[i]->getVenueId() != "Unassigned" &&
			sections[i]->getVenueId() == venueId &&
			sections[i]->getTimeSlot() == timeSlot)
			return true;
	}
	return false;
}

string Scheduler::suggestNextSlot(string venueId)
{
	for (int i = 0; i < timeSlotCount; i++) 
	{
		if (!isVenueBooked(venueId, timeSlots[i]))
			return timeSlots[i];
	}
	return "No slots available";
}


//Har section ko ek venue (room) + time slot assign karna
void Scheduler::generateExamSchedule(Course* courses[], int courseCount)
{
	cout << "Generating exam schedule" << endl;
	for (int i = 0; i < sectionCount; i++)//Schedule one section at a time
	{
		/*cout << "SECTION DEBUG: " << sections[i]->getSectionId() << endl;*/
		cout << "Course ID   : " << sections[i]->getCourseId() << endl;
		cout << "Teacher ID  : " << sections[i]->getTeacherId() << endl;
		cout << "Venue Count : " << venueCount << endl;
		bool assigned = false;
		Course* matched = nullptr;
		for (int c = 0; c < courseCount; c++)
		{
			//Section A kis course ka hai? CS101? CS102?
			//if (courseId match ho jaye section ke courseId se)
			if (courses[c]->getCourseId() == sections[i]->getCourseId())
			{
				matched = courses[c];
				break;
			}
		}
		for (int v = 0; v < venueCount; v++)
		{
			if (matched != nullptr)
			{
				if (!venues[v].canAccommodate(matched->getStudentCount()))
					continue;

				LabCourse* lab = dynamic_cast<LabCourse*>(matched);

				if (lab != nullptr && !venues[v].getHasComputers())
					continue;
			}

			string slot = suggestNextSlot(venues[v].getRoomId());

			if (slot != "No slots available")
			{
				sections[i]->assignVenue(venues[v].getRoomId(), slot);
				assigned = true;
				break;
			}
		}
	}

	cout << "Schedule generation complete!" << endl;
}


void Scheduler::saveSchedule()
{
	ofstream file("exam_schedule.txt");
	if (!file.is_open())
	{
		cout << " ERROR: Cannot save schedule!" << endl;
		return;
	}
	file << "EXAM SCHEDULE\n";
	for (int i = 0; i < sectionCount; i++)
	{
		file << "Section : " << sections[i]->getSectionId() << "\n";
		file << "Course  : " << sections[i]->getCourseId() << "\n";
		file << "Venue   : " << sections[i]->getVenueId() << "\n";
		file << "Time    : " << sections[i]->getTimeSlot() << "\n";
		cout << endl;
	}
	file.close();
	cout << "Schedule saved to exam_schedule.txt!" << endl;
}

void Scheduler::displaySchedule() 
{
	if (sectionCount == 0) 
	{
		cout << "No schedule generated yet." << endl;
		return;
	}
	cout <<"EXAM SCHEDULE" << endl;
	for (int i = 0; i < sectionCount; i++)
	{
		sections[i]->display();//display all scheduled section one by one
		cout << endl;
	}
}
