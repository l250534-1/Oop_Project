#pragma once
//student, Course , Assessment added through its derived classes
#include "Teacher.h"
#include "RegularStudent.h"
#include "ScholarshipStudent.h"
#include "ExchangeStudent.h"
#include "Venue.h"
#include "Section.h"
#include "CoreCourse.h"
#include "ElectiveCourse.h"
#include "LabCourse.h"
#include "Exam.h"
#include "Quiz.h"
#include "Assignment.h"
#include <fstream>
#include<string>
using namespace std;

class DatabaseManager 
{
private:
    string studentsFile;
    string teachersFile;
    string venuesFile;
    string sectionsFile;
    string coursesFile;
    string assessmentsFile;
    string getPart(string line, int index);

public:
    DatabaseManager();
    void saveTeacher(Teacher& t);
    void saveStudent(string id, string name, string email, string type, string extra);
    void saveVenue(Venue& v);
    void saveSection(Section& s);
    void loadStudents(Student* students[], int& count);
    void loadTeachers(Teacher teachers[], int& count);
    void loadVenues(Venue venues[], int& count);
    void loadSections(Section sections[], int& count);
    void loadRegularStudents(RegularStudent students[], int& count);
    void loadScholarshipStudents(ScholarshipStudent students[], int& count);
    void loadExchangeStudents(ExchangeStudent students[], int& count);
    void saveCourse(Course* c);
    void loadCourses(Course* courses[], int& count);
    void saveAssessment(string courseId, Assessment* a);
    void loadAssessments(Course* courses[], int courseCount);
  
};

