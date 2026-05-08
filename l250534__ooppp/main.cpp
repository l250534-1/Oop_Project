#include "RegularStudent.h"
#include "ScholarshipStudent.h"
#include "ExchangeStudent.h"

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

    return 0;
}