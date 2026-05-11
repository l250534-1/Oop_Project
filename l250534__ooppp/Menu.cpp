#include "Menu.h"
#include <iostream>
using namespace std;

Menu::Menu() 
{
    teacherCount = 0;
    regularCount = 0;
    scholarshipCount = 0;
    exchangeCount = 0;
    courseCount = 0;
    venueCount = 0;
    sectionCount = 0;

    db.loadTeachers(teachers, teacherCount);
    db.loadVenues(venues, venueCount);
    db.loadSections(sections, sectionCount);

    for (int i = 0; i < venueCount; i++)
        scheduler.addVenue(venues[i]);
    for (int i = 0; i < sectionCount; i++)
        scheduler.addSection(sections[i]);
}
Menu::~Menu() {
    for (int i = 0; i < courseCount; i++)
        delete courses[i];
}
int Menu::getIntInput(string p) {
    int value;
    while (true) {
        cout << p;
        if (cin >> value) 
        {
            cin.ignore();
            return value;
        }
        cout << "  ERROR: Please enter a valid number!" << endl;
        cin.clear();
        cin.ignore();
    }
}
double Menu::getDoubleInput(string p) {
    double value;
    while (true)
    {
        cout << p;
        if (cin >> value)
        {
            cin.ignore();
            return value;
        }
        cout << "ERROR: Please enter a valid number!" << endl;
        cin.clear();
        cin.ignore();
    }
}
string Menu::getStringInput(string p) {
    string value;
    while (true) {
        cout << p;
        getline(cin, value);
        if (!value.empty()) 
            return value;
        cout << "ERROR: Input cannot be empty!" << endl;
    }
}
bool Menu::isIdUnique(string id)
{
    for (int i = 0; i < teacherCount; i++)
        if (teachers[i].getId() == id) 
            return false;
    for (int i = 0; i < regularCount; i++)
        if (regularStudents[i].getId() == id) 
            return false;
    for (int i = 0; i < scholarshipCount; i++)
        if (scholarshipStudents[i].getId() == id)
            return false;
    for (int i = 0; i < exchangeCount; i++)
        if (exchangeStudents[i].getId() == id) 
            return false;
    return true;
}

bool Menu::isRoomIdUnique(string roomId) {
    for (int i = 0; i < venueCount; i++)
        if (venues[i].getRoomId() == roomId) return false;
    return true;
}

Teacher* Menu::findTeacher(string id)
{
    for (int i = 0; i < teacherCount; i++)
        if (teachers[i].getId() == id)
            return &teachers[i];
    return nullptr;
}

Course* Menu::findCourse(string id) {
    for (int i = 0; i < courseCount; i++)
        if (courses[i]->getCourseId() == id) 
            return courses[i];
    return nullptr;
}
RegularStudent* Menu::findRegular(string id) 
{
    for (int i = 0; i < regularCount; i++)
        if (regularStudents[i].getId() == id) 
            return &regularStudents[i];
    return nullptr;
}

ScholarshipStudent* Menu::findScholarship(string id)
{
    for (int i = 0; i < scholarshipCount; i++)
        if (scholarshipStudents[i].getId() == id) 
            return &scholarshipStudents[i];
    return nullptr;
}

ExchangeStudent* Menu::findExchange(string id)
{
    for (int i = 0; i < exchangeCount; i++)
        if (exchangeStudents[i].getId() == id) 
            return &exchangeStudents[i];
    return nullptr;
}
void Menu::addStudent() {
    cout << "\t\tAdd Student\t\t"<<endl;
    int total = regularCount + scholarshipCount + exchangeCount;
    if (total >= 150) 
    {
        cout << "ERROR: Maximum students reached!" << endl;
       system ("pause");
        return;
    }

    string id;
    while (true)
    {
        id = getStringInput("\tEnter ID : ");
        if (isIdUnique(id))
            break;
        cout << "\tERROR: ID already exists! Try another." << endl;
    }

    string name = getStringInput("\tEnter Name  :");
    string email = getStringInput("\tEnter Email :");

    if (email.find('@') == string::npos)
        cout << "  WARNING: Email looks invalid." << endl;

    cout << "\nStudent Type:" << endl;
    cout << "  1 = Regular" << endl;
    cout << "  2 = Scholarship" << endl;
    cout << "  3 = Exchange" << endl;

    int type = 0;
    while (type < 1 || type > 3)
    {
        type = getIntInput("\tEnter type (1-3): ");
        if (type < 1 || type > 3)
            cout << "ERROR: Enter 1, 2, or 3 only!" << endl;
    }

    if (type == 1) {
        regularStudents[regularCount] = RegularStudent(id, name, email);
        db.saveStudent(id, name, "Regular", 0.0, "");
        regularCount++;
        cout << "\nRegular Student added!" << endl;
    }
    else if (type == 2) {
        double minGPA = 0;
        while (minGPA <= 0 || minGPA > 4.0) {
            minGPA = getDoubleInput("Enter minimum GPA (0.1-4.0): ");
            if (minGPA <= 0 || minGPA > 4.0)
                cout << "ERROR: GPA must be between 0.1 and 4.0!" << endl;
        }
        scholarshipStudents[scholarshipCount] = ScholarshipStudent(id, name, email, minGPA);
        db.saveStudent(id, name, "Scholarship", 0.0, to_string(minGPA));
        scholarshipCount++;
        cout << "\nScholarship Student added!" << endl;
    }
    else
    {
        exchangeStudents[exchangeCount] = ExchangeStudent(id, name, email);
        db.saveStudent(id, name, "Exchange", 0.0, "");
        exchangeCount++;
        cout << "\nExchange Student added!" << endl;
    }
    system("pause");
}


void Menu::viewAllStudents() {

    cout << "\t\tAdd Teacher\t\t" << endl;
    int total = regularCount + scholarshipCount + exchangeCount;
    if (total == 0)
    {
        cout << "  No students found." << endl;
    }
    else
    {
        for (int i = 0; i < regularCount; i++)
        {
            regularStudents[i].displayProfile();
            cout << endl;
        }
        for (int i = 0; i < scholarshipCount; i++)
        {
            scholarshipStudents[i].displayProfile();
            cout << endl;
        }
        for (int i = 0; i < exchangeCount; i++)
        {
            exchangeStudents[i].displayProfile();
            cout << endl;
        }
    }
    system("pause");
}
void Menu::addTeacher() {

    cout << "\t\tAdd Teacher\t\t";

    if (teacherCount >= 50)
    {
        cout << "  ERROR: Maximum teachers reached!" << endl;
        return;
    }
    string id;
    while (true)
    {
        id = getStringInput("\t\tEnter ID  : ");
        if (isIdUnique(id))
            break;
        cout << "\t\tERROR: ID already exists! Try another." << endl;
    }

    string name = getStringInput("\t\tEnter Name  : ");
    string email = getStringInput("\t\tEnter Email : ");

    if (email.find('@') == string::npos)
    {
        cout << "WARNING: Email looks invalid (no @ found)." << endl;
    }

    teachers[teacherCount] = Teacher(id, name, email);
    db.saveTeacher(teachers[teacherCount]);
    teacherCount++;
    cout << "\nTeacher added successfully!" << endl;

}


void Menu::viewAllTeachers()
{

    cout<<"All Teachers"<<endl;
    if (teacherCount == 0)
    {
        cout << "  No teachers found." << endl;
    }
    else
    {
        for (int i = 0; i < teacherCount; i++)
        {
            teachers[i].displayProfile();
            cout << endl;
        }
    }
    system("pause");
}


void Menu::addCourse() {

    cout << "\t\tAdd Course\t\t";

    if (courseCount >= 50)
    {
        cout << "ERROR: Maximum courses reached!" << endl;
        system("pause");
        return;
    }

    string id;
    while (true)
    {
        id = getStringInput("Enter Course ID  : ");
        if (findCourse(id) == nullptr)
            break;
        cout << "ERROR: Course ID already exists!" << endl;
    }

    string title = getStringInput("Enter Title      : ");
    string teacherId = getStringInput("Enter Teacher ID : ");

    if (findTeacher(teacherId) == nullptr)
        cout << "WARNING: Teacher ID not found in system." << endl;

    cout << "\nCourse Type:" << endl;
    cout << "1 = Core (3hr exam)" << endl;
    cout << "2 = Elective (2hr exam)" << endl;
    cout << "3 = Lab (no exam, needs computers)" << endl;

    int type = 0;
    while (type < 1 || type > 3)
    {
        type = getIntInput("  Enter type (1-3): ");
        if (type < 1 || type > 3)
            cout << "  ERROR: Enter 1, 2, or 3 only!" << endl;
    }

    if (type == 1)
        courses[courseCount] = new CoreCourse(id, title, teacherId);
    else if (type == 2)
        courses[courseCount] = new ElectiveCourse(id, title, teacherId);
    else
        courses[courseCount] = new LabCourse(id, title, teacherId);

    courseCount++;
    cout << "\n  Course added successfully!" << endl;
    system("pause");
}
    

void Menu::viewAllCourses() {

    cout << "All Courses" << endl;
    if (courseCount == 0)
    {
        cout << "No courses found." << endl;
    }
    else {
        for (int i = 0; i < courseCount; i++) {
            cout << "  ID     : " << courses[i]->getCourseId() << endl;
            cout << "  Title  : " << courses[i]->getTitle() << endl;
            cout << "  Type   : " << courses[i]->getCourseType() << endl;
            cout << "  Teacher: " << courses[i]->getTeacherId() << endl;
            cout << "  Students enrolled: " << courses[i]->getStudentCount() << endl;
            cout << endl;
        }
    }
    system("pause");
}

void Menu::addVenue() {

    cout << "\t\tAdd Venue\t\t";

    if (venueCount >= 20) {
        cout << "  ERROR: Maximum venues reached!" << endl;
        system("pause");
        return;
    }

    string roomId;
    while (true)
    {
        roomId = getStringInput("  Enter Room ID  : ");
        if (isRoomIdUnique(roomId))
            break;
        cout << "ERROR: Room ID already exists!" << endl;
    }

    int capacity = 0;
    while (capacity <= 0)
    {
        capacity = getIntInput("Enter Capacity : ");
        if (capacity <= 0)
            cout << "ERROR: Capacity must be greater than 0!" << endl;
    }

    int comp = -1;
    while (comp != 0 && comp != 1)
    {
        comp = getIntInput("Has Computers? (1=Yes / 0=No): ");
        if (comp != 0 && comp != 1)
            cout << "ERROR: Enter 1 or 0 only!" << endl;
    }

    venues[venueCount] = Venue(roomId, capacity, comp == 1);
    db.saveVenue(venues[venueCount]);
    scheduler.addVenue(venues[venueCount]);
    venueCount++;
    cout << "\n  Venue added successfully!" << endl;
    system("pause");
}
