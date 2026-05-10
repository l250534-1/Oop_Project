#include "RegularStudent.h"
#include "ScholarshipStudent.h"
#include "ExchangeStudent.h"
/*#include "Assignment.h"*/
//#include "Quiz.h"
#include "Exam.h"
//#include<"Assessment.h">
#include"Venue.h"
#include "DatabaseManager.h"
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

}