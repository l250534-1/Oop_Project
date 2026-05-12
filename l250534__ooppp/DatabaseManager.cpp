#include "DatabaseManager.h"
#include <iostream>
#include <fstream>
using namespace std;

DatabaseManager::DatabaseManager()
{
    studentsFile = "Students.txt";
    teachersFile = "Teachers.txt";
    venuesFile = "Venues.txt";
    sectionsFile = "Sections.txt";
    coursesFile = "Courses.txt";
    assessmentsFile = "assessments.txt";

}

string DatabaseManager::getPart(string line, int index)// " | " delimeter
{
    int count = 0;
    //count is how many things stored,id,name,cours 101|Ali|cs1002
    string part = "";
    for (int i = 0; i < (int)line.length(); i++) //string function returns the number of characters in the string.
    {
        if (line[i] == '|')
        {
            if (count == index) 
                return part;
            count++;
            part = "";//reset
        }
        else
        {
            part += line[i];
        }
    }
    if (count == index) 
        return part;
    return "";
}

void DatabaseManager::saveTeacher(Teacher& t) //by refrence passed(no copy)
{
    ofstream file(teachersFile, ios::app);//file is obj name
    //filename, mode append adds data at END of file
    //created (or overwritten)
    if (file.is_open()) 
    {
        file << t.getId() << "|"
            << t.getName() << "|"
            << t.getEmail() << "|"
            << t.getAverageScore() << "\n";
        file.close();
    }
}

void DatabaseManager::saveStudent(string id, string name, string email, string type, string extra)
{
    ofstream file(studentsFile, ios::app);
    if (file.is_open()) 
    {
        file << id << "|"
            << name << "|"
            << email << "|"
            << type << "|"
            << extra << "\n";
        file.close();
    }
}

void DatabaseManager::loadTeachers(Teacher teachers[], int& count) 
{
    ifstream file(teachersFile);//read data
    count = 0;
    if (!file.is_open())
        return;
    string line;
    while (getline(file, line) && count < 50)//till EOF    when\n new line 
    {
        if (line.empty()) 
            continue;
        string id = getPart(line, 0);
        string name = getPart(line, 1);
        string email = getPart(line, 2);
        string avgStr = getPart(line, 3);
        teachers[count] = Teacher(id, name, email);
        count++;
    }
    file.close();
}
void DatabaseManager::loadStudents(Student* students[], int& count)
{
    ifstream file(studentsFile);

    count = 0;

    if (!file.is_open())
        return;

    string line;

    while (getline(file, line))
    {
        string id = getPart(line, 0);
        string name = getPart(line, 1);
        string email = getPart(line, 2);
        string type = getPart(line, 3);
        string extra = getPart(line, 4);


        if (type == "Regular")
        {
            students[count] =
                new RegularStudent(id, name, "");
        }

        else if (type == "Scholarship")
        {
            students[count] =
                new ScholarshipStudent(id, name, "", 2.5);
        }

        else if (type == "Exchange")
        {
            students[count] =
                new ExchangeStudent(id, name, "");
        }

        count++;
    }

    file.close();
}

void DatabaseManager::saveVenue(Venue& v) 
{
    ofstream file(venuesFile, ios::app);
    if (file.is_open()) 
    {
        file << v.getRoomId() << "|"
            << v.getCapacity() << "|"
            << v.getHasComputers() << "\n";
        file.close();
    }
}

void DatabaseManager::saveSection(Section& s)
{
    ofstream file(sectionsFile, ios::app);
    if (file.is_open())
    {
        file << s.getSectionId() << "|"
            << s.getCourseId() << "|"
            << s.getTeacherId() << "|"
            << s.getVenueId() << "|"
            << s.getTimeSlot() << "\n";
        file.close();
    }
}

void DatabaseManager::loadVenues(Venue venues[], int& count) 
{
    ifstream file(venuesFile);
    count = 0;
    if (!file.is_open()) 
        return;
    string line;
    while (getline(file, line) && count < 20) 
    {
        if (line.empty()) 
            continue;
        string roomId = getPart(line, 0);
        int  cap = stoi(getPart(line, 1)); //string to int
        bool comp = stoi(getPart(line, 2));
        venues[count] = Venue(roomId, cap, comp);
        count++;
    }
    file.close();
}

void DatabaseManager::loadSections(Section sections[], int& count) 
{
    ifstream file(sectionsFile);
    count = 0;
    if (!file.is_open()) 
        return;
    string line;
    while (getline(file, line) && count < 100) {
        if (line.empty())
            continue;
        string sid = getPart(line, 0);
        string cid = getPart(line, 1);
        string tid = getPart(line, 2);
        string vid = getPart(line, 3);
        string slot = getPart(line, 4);
        Section temp(sid, cid, tid);
        if (vid != "Unassigned" && slot != "Unassigned")
        {
            temp.assignVenue(vid, slot);
        }
     /*   sections[count] = Section(sid, cid, tid);
        sections[count].assignVenue(vid, slot);
        count++;*/

        sections[count] = temp;
        count++;
    }
    file.close();
}


void DatabaseManager::loadRegularStudents(RegularStudent students[], int& count) {
    ifstream file(studentsFile);
    count = 0;
    if (!file.is_open()) 
        return;
    string line;
    while (getline(file, line) && count < 50)
    {
        if (line.empty()) 
            continue;
        string id = getPart(line, 0);
        string name = getPart(line, 1);
        string email = getPart(line, 2); 
        string type = getPart(line, 3);  
        if (type == "Regular") {
            students[count] = RegularStudent(id, name, email); 
            count++;
        }
    }
    file.close();
}

void DatabaseManager::loadScholarshipStudents(ScholarshipStudent students[], int& count) {
    ifstream file(studentsFile);
    count = 0;
    if (!file.is_open())
        return;
    string line;
    while (getline(file, line) && count < 50) {
        if (line.empty()) 
            continue;
        string id = getPart(line, 0);
        string name = getPart(line, 1);
        string email = getPart(line, 2);  
        string type = getPart(line, 3);  
        string mingpa = getPart(line, 4);
        if (type == "Scholarship")
        {
            double minGPA = 2.0;
            if (!mingpa.empty()) 
                minGPA = stod(mingpa);//string to double
            students[count] = ScholarshipStudent(id, name, email, minGPA);
            count++;
        }
    }
    file.close();
}
 
void DatabaseManager::loadExchangeStudents(ExchangeStudent students[], int& count) {
    ifstream file(studentsFile);
    count = 0;
    if (!file.is_open())
        return;
    string line;
    while (getline(file, line) && count < 50) {
        if (line.empty()) 
            continue;
        string id = getPart(line, 0);
        string name = getPart(line, 1);
        string email = getPart(line, 2);  
        string type = getPart(line, 3);  
        if (type == "Exchange") {
            students[count] = ExchangeStudent(id, name, email);  
            count++;
        }
    }
    file.close();
}

void DatabaseManager::saveCourse(Course* c) {
    ofstream file(coursesFile, ios::app);
    if (file.is_open())
    {
        file << c->getCourseId() << "|"
            << c->getTitle() << "|"
            << c->getTeacherId() << "|"
            << c->getCourseType() << "\n";
        file.close();
    }
}

void DatabaseManager::loadCourses(Course* courses[], int& count) {
    ifstream file(coursesFile);
    count = 0;
    if (!file.is_open())
        return;
    string line;
    while (getline(file, line) && count < 50) {
        if (line.empty()) 
            continue;
        string id = getPart(line, 0);
        string title = getPart(line, 1);
        string teacher = getPart(line, 2);
        string type = getPart(line, 3);
        if (type == "Core")
            courses[count] = new CoreCourse(id, title, teacher);
        else if (type == "Elective")
            courses[count] = new ElectiveCourse(id, title, teacher);
        else if (type == "Lab")
            courses[count] = new LabCourse(id, title, teacher);
        count++;
    }
    file.close();
}

void DatabaseManager::saveAssessment(string courseId, Assessment* a) {
    ofstream file(assessmentsFile, ios::app);
    if (file.is_open())
    {
        file << courseId << "|"
            << a->getStudentId() << "|"
            << a->getType() << "|"
            << a->getRawScore() << "|"
            << a->getMaxScore() << "|"
            << a->getWeightage() << "\n";
        file.close();
    }
}

void DatabaseManager::loadAssessments(Course* courses[], int courseCount)
{
    ifstream file(assessmentsFile);
    if (!file.is_open()) 
        return;

    string line;

    while (getline(file, line))
    {
        if (line.empty()) 
            continue;

        string courseId = getPart(line, 0);
        string studentId = getPart(line, 1);
        string type = getPart(line, 2);
        double raw = stod(getPart(line, 3));
        double max = stod(getPart(line, 4));
        double weightage = stod(getPart(line, 5));

        for (int i = 0; i < courseCount; i++)
        {
            if (courses[i]->getCourseId() == courseId)
            {
                if (type == "Exam")
                    courses[i]->addAssessment(new Exam(studentId, raw, max, weightage));
                else if (type == "Quiz")
                    courses[i]->addAssessment(new Quiz(studentId, raw, max, weightage));
                else
                    courses[i]->addAssessment(new Assignment(studentId, raw, max, weightage));

                break;
            }
        }
    }
}



