#include "RegularStudent.h"
#include "ScholarshipStudent.h"
#include "ExchangeStudent.h"
/*#include "Assignment.h"*/
//#include "Quiz.h"
#include "Exam.h"
//#include<"Assessment.h">
#include"Venue.h"
#include"Teacher.h"
#include "DatabaseManager.h"
#include "Scheduler.h"
#include "CoreCourse.h"
#include "ElectiveCourse.h"
#include "LabCourse.h"
#include <iostream>
using namespace std;

int main()
{
    // Regular Student
    RegularStudent r1("24K-1001", "Ali", "ali@gmail.com");

    r1.addGrade(85);
    r1.addGrade(90);

    r1.displayProfile();
    r1.viewTranscript();


    // Scholarship Student
    ScholarshipStudent s1("24K-2001", "Sara", "sara@gmail.com", 85);

    s1.addGrade(70);
    s1.addGrade(75);

    s1.displayProfile();
    s1.viewTranscript();


    // Exchange Student
    ExchangeStudent e1("24K-3001", "John", "john@gmail.com");

    e1.addResult("Pass");
    e1.addResult("Fail");

    e1.displayProfile();
    e1.viewTranscript();
    /*Assignment a1(50, 100, 10);
    a1.calculateWeightedScore();
    a1.display();*/
 /*  Quiz a2(50, 100, 10);
    a2.calculateWeightedScore();
    a2.display();*/
   Exam a3(50, 100, 10);
    a3.calculateWeightedScore();
    a3.display();



    //Assessment a("Exam", 50,100,10);
    //virtual double calculateWeightedScore() = 0;//abstarct class
    //virtual void   display() = 0;
    //string getType();
    //double getRawScore();
    //double getMaxScore();
    //double getWeightage();
    //return 0;


   /* r1.enrollinCourse("CS200");
    r1.enrollinCourse("SE101");
    cout<<  r1.getName();
    for (int i = 0; i < r1.getEnrolledCount(); i++)
    {
         cout   << r1.getEnrolledCourse(i)
            << endl;
    }*/

    Venue v1("Lab-101", 40, true);

    v1.display();

    cout << endl;

    if (v1.canAccommodate(35))
    {
        cout << "Room can accommodate students." << endl;
    }
    else
    {
        cout << "Room is too small." << endl;
    }
    DatabaseManager db;
    db.saveStudent(
        r1.getId(),
        r1.getName(),
        r1.getType(),
        r1.calculateGPA(),
        "None"
    );

    db.saveStudent(
        s1.getId(),
        s1.getName(),
        s1.getType(),
        s1.calculateGPA(),
        "2.5"
    );

    db.saveStudent(
        e1.getId(),
        e1.getName(),
        e1.getType(),
        e1.calculateGPA(),
        "PassFail"
    );

    cout << "Students saved";
        Student * students[100];

    int studentCount = 0;

    db.loadStudents(students, studentCount);

    cout << endl;
    cout << "Loaded Students";

    

    db.saveVenue(v1);

    cout << "Venue saved";
    Venue venues[20];

    int venueCount = 0;

    db.loadVenues(venues, venueCount);

    cout << endl;
    cout << "Loaded Venues";
    for (int i = 0; i < venueCount; i++)
    {
        venues[i].display();
        cout << endl;
    }
    for (int i = 0; i < studentCount; i++)
    {
        students[i]->displayProfile();
        cout << endl;
    }

    Teacher t1(
        "T-101",
        "Dr Ahmed",
        "ahmed@fast.edu.pk"
    );

    Teacher t2(
        "T-102",
        "Ms Sara",
        "sara@fast.edu.pk"
    );

    db.saveTeacher(t1);
    db.saveTeacher(t2);

    cout << "Teachers saved";


    for (int i = 0; i < studentCount; i++)
    {
        delete students[i];
    }
    Teacher teachers[50];

    int teacherCount = 0;

    db.loadTeachers(teachers, teacherCount);

    cout << endl;
    cout << "Loaded Teachers";
    for (int i = 0; i < teacherCount; i++)
    {
        teachers[i].displayProfile();
        cout << endl;
    }



    Scheduler sch;

    Venue v2("A-301", 50, false);
    Venue v3("Lab-201", 40, true);

    sch.addVenue(v2);
    sch.addVenue(v3);

    CoreCourse c1("CS200", "OOP", "T-101");
    ElectiveCourse c2("AI201", "Artificial Intelligence", "T-102");
    LabCourse c3("CS210L", "OOP Lab", "T-101");

    for (int i = 0; i < 35; i++)
    {
        c1.enrollStudent("S");
        c2.enrollStudent("S");
        c3.enrollStudent("S");
    }

    Course* courses[3];

    courses[0] = &c1;
    courses[1] = &c2;
    courses[2] = &c3;

    Section sec1("SEC-A", "CS200", "T-101");
    Section sec2("SEC-B", "AI201", "T-102");
    Section sec3("SEC-C", "CS210L", "T-101");

    sch.addSection(sec1);
    sch.addSection(sec2);
    sch.addSection(sec3);

    sch.generateExamSchedule(courses, 3);

    cout << endl;

    sch.displaySchedule();

    sch.saveSchedule();
















}