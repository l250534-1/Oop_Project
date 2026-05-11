#pragma once
#include "DatabaseManager.h"
#include "Scheduler.h"
#include "CoreCourse.h"
#include "ElectiveCourse.h"
#include "LabCourse.h"
#include "RegularStudent.h"
#include "ScholarshipStudent.h"
#include "ExchangeStudent.h"
#include "Exam.h"
#include "Quiz.h"
#include "Assignment.h"



class Menu {
private:
    Teacher teachers[50];
    int teacherCount;
    RegularStudent regularStudents[50];
    int regularCount;
    ScholarshipStudent scholarshipStudents[50];
    int scholarshipCount;
    ExchangeStudent exchangeStudents[50];
    int exchangeCount;
    Course* courses[50];
    int courseCount;
    Venue venues[20];
    int venueCount;
    Section sections[100];
    int sectionCount;

    DatabaseManager db;
    Scheduler scheduler;
public:
    Menu();
    ~Menu();
    int getIntInput(string p);
    double  getDoubleInput(string p);
    string  getStringInput(string p);
    bool    isIdUnique(string id);
    bool    isRoomIdUnique(string roomId);
    Teacher* findTeacher(string id);
    Course* findCourse(string id);
    RegularStudent* findRegular(string id);
    ScholarshipStudent* findScholarship(string id);
    ExchangeStudent* findExchange(string id);
    void addStudent();
    void viewAllStudents();
    void addTeacher();
    void viewAllTeachers();
};