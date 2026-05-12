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

    db.loadRegularStudents(regularStudents, regularCount);
    db.loadScholarshipStudents(scholarshipStudents, scholarshipCount);
    db.loadExchangeStudents(exchangeStudents, exchangeCount);
    db.loadCourses(courses, courseCount);
    db.loadAssessments(courses, courseCount);
    for (int i = 0; i < venueCount; i++)
        scheduler.addVenue(venues[i]);
    for (int i = 0; i < sectionCount; i++)
        scheduler.addSection(sections[i]);
}
Menu::~Menu()//destructor
{
    for (int i = 0; i < courseCount; i++)
        delete courses[i];
}

int Menu::getIntInput(string p)
{
    int value;
    bool valid;
    do
    {
        valid = true;
        cout << p;
        if (!(cin >> value))//special characters entered
        {
            cout << "ERROR: Please enter a valid integer!" << endl;
            cin.clear();
            cin.ignore(1000, '\n');
            valid = false;
        }
        else if (value < 0)
        {
            cout << "ERROR: Negative values are not allowed!" << endl;
            cin.ignore(1000,'\n');
            valid = false;
        }
        else
        {
            cin.ignore(1000, '\n');
        }
    } while (!valid);
    return value;
}

double Menu::getDoubleInput(string p)
{
    double value;
    bool valid;
    do
    {
        valid = true;
        cout << p;
        if (!(cin >> value))
        {
            cout << "ERROR: Please enter a valid number!" << endl;
            cin.clear();
            cin.ignore(1000, '\n');
            valid = false;
        }
        else if (value < 0)
        {
            cout << "ERROR: Negative values are not allowed!" << endl;
            cin.ignore(1000, '\n');
            valid = false;
        }
        else
        {
            cin.ignore(1000,'\n');
        }
    } while (!valid);

    return value;
}
   
string Menu::getStringInput(string p)
{
    string value;
    do
    {
        cout << p;
        getline(cin, value);

        if (value.empty())//used built in function for string
        {
            cout << "ERROR: Input cannot be empty!" << endl;
        }

    } while (value.empty());
    return value;
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

bool Menu::isRoomIdUnique(string roomId)
{
    for (int i = 0; i < venueCount; i++)
        if (venues[i].getRoomId() == roomId) 
            return false;
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
    cout << "Add Student"<<endl;
    int total = regularCount + scholarshipCount + exchangeCount;
    if (total >= 150) 
    {
        cout << "ERROR: Maximum students reached!" << endl;
       system ("pause");
        return;
    }

    string id;
    do
    {
        id = getStringInput("Enter ID : ");
        if (id[0] == '-')//-123 - detects negatve
        {
            cout << "ERROR: ID cannot be negative!" << endl;
        }
        else if (!isIdUnique(id))
        {
            cout << "ERROR: ID already exists! Try another." << endl;
        }

    } while (id[0] == '-' || !isIdUnique(id));

    string name = getStringInput("Enter Name  :");
    string email;

    do {
        email = getStringInput("Enter Email : ");
        bool found = false;
        for (int i = 0; i < (int)email.length(); i++) {
            if (email[i] == '@') { found = true; break; }
        }
        if (!found)
            cout << "ERROR: Invalid email! Must contain @" << endl;
        else
            break;
    } while (true);

    cout << "\nStudent Type:\n" << endl;
    cout << "1 = Regular" << endl;
    cout << "2 = Scholarship" << endl;
    cout << "3 = Exchange" << endl;

    int type = 0;
    while (type < 1 || type > 3)
    {
        type = getIntInput("Enter type (1-3):\n");
        if (type < 1 || type > 3)
            cout << "ERROR: Enter 1, 2, or 3 only!" << endl;
    }

    if (type == 1) {
        regularStudents[regularCount] = RegularStudent(id, name, email);
        db.saveStudent(id, name, email, "Regular", "");
        regularCount++;
        cout << "\nRegular Student added!" << endl;
    }
    else if (type == 2) {
        double minGPA = 0;
      
        do
        {
            minGPA = getDoubleInput("Enter minimum GPA (0.1-4.0): ");
            if (minGPA <= 0 || minGPA > 4.0)
                cout << "ERROR: GPA must be between 0.1 and 4.0!" << endl;
        } while (minGPA <= 0 || minGPA > 4.0);

        scholarshipStudents[scholarshipCount] = ScholarshipStudent(id, name, email, minGPA);
        db.saveStudent(id, name, email, "Scholarship", to_string(minGPA));
        scholarshipCount++;
        cout << "\nScholarship Student added!" << endl;
    }
    else
    {
        exchangeStudents[exchangeCount] = ExchangeStudent(id, name, email);
        db.saveStudent(id, name, email, "Exchange", "");
        exchangeCount++;
        cout << "\nExchange Student added!" << endl;
    }
    system("pause");
}


void Menu::viewAllStudents() {

    cout << "Students" << endl;
    int total = regularCount + scholarshipCount + exchangeCount;
    if (total == 0)
    {
        cout << "No students found." << endl;
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

    cout << "Add Teacher";

    if (teacherCount >= 50)
    {
        cout << "  ERROR: Maximum teachers reached!" << endl;
        return;
    }

    string id;
    do
    {
        id = getStringInput("Enter ID : ");
        if (id[0] == '-')
            cout << "ERROR: ID cannot be negative!" << endl;
        else if (!isIdUnique(id))
            cout << "ERROR: ID already exists! Try another." << endl;
    } while (id[0] == '-' || !isIdUnique(id));

    string name = getStringInput("Enter Name  : ");
    string email;

    do {
        email = getStringInput("Enter Email : ");
        if (email.find('@') == string::npos)
            cout << "ERROR: Invalid email! Must contain @" << endl;
    } while (email.find('@') == string::npos);

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

    cout << "Add Course";

    if (courseCount >= 50)
    {
        cout << "ERROR: Maximum courses reached!" << endl;
        system("pause");
        return;
    }

    string id;
    do 
    {
        id = getStringInput("Enter Course ID : ");
        if (findCourse(id) != nullptr)
            cout << "ERROR: Course ID already exists! Try another." << endl;
    } while (findCourse(id) != nullptr);

    string title = getStringInput("Enter Title      : ");
   
    string teacherId;
    do
    {
        teacherId = getStringInput("Enter Teacher ID : ");
        if (findTeacher(teacherId) == nullptr)
            cout << "ERROR: Teacher not found! Enter valid Teacher ID." << endl;
    } while (findTeacher(teacherId) == nullptr);

    cout << "\nCourse Type:" << endl;
    cout << "1 = Core (3hr exam)" << endl;
    cout << "2 = Elective (2hr exam)" << endl;
    cout << "3 = Lab (no exam, needs computers)" << endl;

    int type = 0;
    while (type < 1 || type > 3)
    {
        type = getIntInput("  Enter type (1-3): ");
        if (type < 1 || type > 3)
            cout << "ERROR: Enter 1, 2, or 3 only!" << endl;
    }

    if (type == 1)
        courses[courseCount] = new CoreCourse(id, title, teacherId);
    else if (type == 2)
        courses[courseCount] = new ElectiveCourse(id, title, teacherId);
    else
        courses[courseCount] = new LabCourse(id, title, teacherId);

    courseCount++;
    db.saveCourse(courses[courseCount - 1]);
    cout << "\nCourse added successfully!" << endl;
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

    cout << "Add Venue";

    if (venueCount >= 20) {
        cout << "ERROR: Maximum venues reached!" << endl;
        system("pause");
        return;
    }
    string roomId;
    do 
    {
        roomId = getStringInput("Enter Room ID : ");
        if (!isRoomIdUnique(roomId))
            cout << "ERROR: Room ID already exists!" << endl;
    } while (!isRoomIdUnique(roomId));

    int capacity;
    do
    {
        capacity = getIntInput("Enter Capacity : ");
        if (capacity <= 0)
            cout << "ERROR: Capacity must be greater than 0!" << endl;
    } while (capacity <= 0);

    int comp;
    do 
    {
        comp = getIntInput("Has Computers? (1=Yes / 0=No): ");
        if (comp != 0 && comp != 1)
            cout << "ERROR: Enter 1 or 0 only!" << endl;
    } while (comp != 0 && comp != 1);

    venues[venueCount] = Venue(roomId, capacity, comp == 1);
    db.saveVenue(venues[venueCount]);
    scheduler.addVenue(venues[venueCount]);
    venueCount++;
    cout << "\nVenue added successfully!" << endl;
    system("pause");
}


void Menu::addSection()
{

    cout << "Add Section";

    if (sectionCount >= 100)
    {
        cout << "ERROR: Maximum sections reached!" << endl;
        system("pause");
        return;
    }

    if (courseCount == 0) {
        cout << "ERROR: No courses exist. Add a course first!" << endl;
        system("pause");
        return;
    }

    string sectionId;
    do {
        sectionId = getStringInput("  Enter Section ID : ");
        bool duplicate = false;
        for (int i = 0; i < sectionCount; i++) {
            if (sections[i].getSectionId() == sectionId) {
                duplicate = true;
                break;
            }
        }
        if (duplicate)
            cout << "  ERROR: Section ID already exists!" << endl;
        else
            break;
    } while (true);

    string courseId;
    do {
        courseId = getStringInput("  Enter Course ID  : ");
        if (findCourse(courseId) == nullptr)
            cout << "  ERROR: Course not found! Enter a valid Course ID." << endl;
        else
            break;
    } while (true);  


    string teacherId;
    do {
        teacherId = getStringInput("  Enter Teacher ID : ");
        if (findTeacher(teacherId) == nullptr)
            cout << "  ERROR: Teacher not found! Enter a valid Teacher ID." << endl;
        else
            break;
    } while (true);

  
    sections[sectionCount] = Section(sectionId, courseId, teacherId);
    db.saveSection(sections[sectionCount]);
    scheduler.addSection(sections[sectionCount]);
    sectionCount++;
    cout << "\nSection added!" << endl;
    system("pause");
}

void Menu::registerStudentToCourse() {

    cout << "Register Student to Course";

    if (courseCount == 0)
    {
        cout << "ERROR: No courses exist!" << endl;
        system("pause");
        return;
    }

    string studentId;
    do {
        studentId = getStringInput("Enter Student ID : ");
        bool exists = findRegular(studentId) != nullptr ||
            findScholarship(studentId) != nullptr ||
            findExchange(studentId) != nullptr;
        if (!exists)
            cout << "ERROR: Student not found! Try again." << endl;
        else
            break;
    } while (true);

    string courseId;
    do {
        courseId = getStringInput("Enter Course ID : ");
        if (findCourse(courseId) == nullptr)
            cout << "ERROR: Course not found! Try again." << endl;
        else
            break;
    } while (true);

   

    Course* course = findCourse(courseId);
    

    if (course->isStudentEnrolled(studentId))
    {
        cout << "ERROR: Student already enrolled in this course!" << endl;
        system("pause");
        return;
    }

    bool ok = course->enrollStudent(studentId);
    if (ok)
    {
        //  enroll in student object
        RegularStudent* r = findRegular(studentId);
        if (r)
            r->enrollinCourse(courseId);
        ScholarshipStudent* s = findScholarship(studentId);
        if (s)
            s->enrollinCourse(courseId);
        ExchangeStudent* e = findExchange(studentId);
        if (e)
            e->enrollinCourse(courseId);
        cout << "\nRegistration successful!" << endl;
    }
    system("pause");
}



void Menu::enterMarks() {

    cout <<"Enter Marks";

    if (courseCount == 0) {
        cout << "ERROR: No courses exist!" << endl;
        system("pause");
        return;
    }
    string courseId;
    Course* course;
    string studentId;
    do
    {
        courseId = getStringInput("Enter Course ID : ");
        course = findCourse(courseId);
        if (course == nullptr)
            cout << "ERROR: Course not found! Try again." << endl;
    } while (course == nullptr);

    do {
        studentId = getStringInput("Enter Student ID : ");

        bool exists =
            findRegular(studentId) != nullptr ||
            findScholarship(studentId) != nullptr ||
            findExchange(studentId) != nullptr;

        if (!exists)
            cout << "ERROR: Student not found!" << endl;
        else
            break;

    } while (true);

    cout << "\nAssessment Type:" << endl;
    cout << "1 = Exam" << endl;
    cout << "2 = Quiz" << endl;
    cout << "3 = Assignment" << endl;

    int type = 0;
    while (type < 1 || type > 3) {
        type = getIntInput("Enter type (1-3): ");
        if (type < 1 || type > 3)
            cout << "ERROR: Enter 1, 2, or 3!" << endl;
    }

    // Lab courses cannot have exams
    LabCourse* lab = dynamic_cast<LabCourse*>(course);
    if (lab != nullptr && type == 1) {
        cout << "ERROR: Lab courses cannot have Exams!" << endl;
        system("pause");
        return;
    }

    double raw = -1, max = -1, wt = -1;

    while (raw < 0) {
        raw = getDoubleInput("Enter raw score : ");
        if (raw < 0)
            cout << "ERROR: Score cannot be negative!" << endl;
    }

    while (max <= 0)
    {
        max = getDoubleInput("Enter max score : ");
        if (max <= 0)
            cout << "ERROR: Max score must be greater than 0!" << endl;
    }

    if (raw > max)
    {
        cout << "ERROR: Raw score cannot exceed max score!" << endl;
        system("pause");
        return;
    }

    while (wt <= 0 || wt > 100)
    {
        wt = getDoubleInput("Enter weightage (1-100): ");
        if (wt <= 0 || wt > 100)
            cout << "ERROR: Weightage must be between 1 and 100!" << endl;
    }

    if (type == 1) {
        Exam* ex = new Exam(studentId, raw, max, wt);
        course->addAssessment(ex);
        db.saveAssessment(courseId, ex);
    }
    else if (type == 2) {
        Quiz* qz = new Quiz(studentId, raw, max, wt);
        course->addAssessment(qz);
        db.saveAssessment(courseId, qz);
    }
    else {
        Assignment* as = new Assignment(studentId, raw, max, wt);
        course->addAssessment(as);
        db.saveAssessment(courseId, as);
    }
    cout << endl;
    course->displayAssessments(studentId);
    double finalGrade = course->calculateFinalGrade(studentId);
    cout << "\nFinal Grade: " << finalGrade << "%" << endl;


    double gpaPoints = percentageToGPA(finalGrade);

 

    // add pass/fail for exchange students
    for (int i = 0; i < exchangeCount; i++) {
        if (course->isStudentEnrolled(exchangeStudents[i].getId())) {
            if (finalGrade >= 50)
                exchangeStudents[i].addResult("Pass");
            else
                exchangeStudents[i].addResult("Fail");
            cout << exchangeStudents[i].getName() << " result: "
                << (finalGrade >= 50 ? "Pass" : "Fail") << endl;
        }
    }
    int credits = 0;

    if (course->getCourseType() == "Core")
        credits = 3;
    else if (course->getCourseType() == "Elective")
        credits = 2;
    else
        credits = 1;

    double weightedPoints = (finalGrade / 100.0) * 4.0 * credits;

    RegularStudent* r = findRegular(studentId);
    if (r != nullptr)
        r->addGrade(weightedPoints, credits);

    ScholarshipStudent* s = findScholarship(studentId);
    if (s != nullptr)
        s->addGrade(weightedPoints, credits);
    system("pause");
}

double Menu::percentageToGPA(double percent)
{
    if (percent >= 85) return 4.0;
    else if (percent >= 80) return 3.7;
    else if (percent >= 75) return 3.3;
    else if (percent >= 70) return 3.0;
    else if (percent >= 65) return 2.7;
    else if (percent >= 60) return 2.3;
    else return 0.0;
}

void Menu::viewTranscript() {
    cout << "View Transcript" << endl;

    string id;
    RegularStudent* r = nullptr;
    ScholarshipStudent* s = nullptr;
    ExchangeStudent* e = nullptr;

    do {
        id = getStringInput("Enter Student ID : ");
        r = findRegular(id);
        s = findScholarship(id);
        e = findExchange(id);
        if (r == nullptr && s == nullptr && e == nullptr)
            cout << "ERROR: Student not found! Try again." << endl;
    } while (r == nullptr && s == nullptr && e == nullptr);
    
    if (r != nullptr)
        r->viewTranscript();
    else if (s != nullptr)
        s->viewTranscript();
    else if (e != nullptr)
        e->viewTranscript();
    system("pause");
}

void Menu::leaveFeedback() {

    cout << "Leave Feedback for Teacher";

    if (teacherCount == 0)
    {
        cout << "ERROR: No teachers exist!" << endl;
        system("pause");
        return;
    }

    string id;
    Teacher* teacher;
    do {
        id = getStringInput("Enter Teacher ID : ");
        teacher = findTeacher(id);
        if (teacher == nullptr)
            cout << "ERROR: Teacher not found! Try again." << endl;
    } while (teacher == nullptr);

    int rating = 0;
    while (rating < 1 || rating > 5)
    {
        rating = getIntInput("Enter rating (1-5): ");
        if (rating < 1 || rating > 5)
            cout << "ERROR: Rating must be between 1 and 5!" << endl;
    }

    teacher->addFeedback(rating);
    cout << "\nFeedback submitted!" << endl;
    cout << "New Average Score: " << teacher->getAverageScore() << "/5" << endl;
    system("pause");
}

void Menu::generateSchedule() {

    cout << "Generate Exam Schedule";

    if (sectionCount == 0)
    {
        cout << "ERROR: No sections exist! Add sections first." << endl;
        system("pause");
        return;
    }
    if (venueCount == 0) {
        cout << "ERROR: No venues exist! Add venues first." << endl;
        system("pause");
        return;
    }

    scheduler.generateExamSchedule(courses, courseCount);
    scheduler.saveSchedule();
    system("pause");
}

void Menu::viewSchedule()
{

    cout << "Exam Schedule";
    scheduler.displaySchedule();
    system("pause");
}


                                              //Student Menu
void Menu::studentMenu() {
    int choice = 0;
    while (choice != 5) {

        cout << "Student Menu\n";
        cout << "1. Add Student" << endl;
        cout << "2. View All Students" << endl;
        cout << "3. Register Student to Course" << endl;
        cout << "4. View Transcript" << endl;
        cout << "5. Back" << endl;
        choice = getIntInput("\n Enter choice (1-5): ");
        if (choice == 1)
            addStudent();
        else if (choice == 2)
            viewAllStudents();
        else if (choice == 3)
            registerStudentToCourse();
        else if (choice == 4)
            viewTranscript();
        else if (choice == 5)
            return;
        else
            cout << "\n ERROR: Invalid choice!" << endl;
    }
}
                                         //Teacher Menu
void Menu::teacherMenu() {
    int choice = 0;
    while (choice != 5) {

        cout << "Teacher Menu"<<endl;
        cout << "1. Add Teacher" << endl;
        cout << "2. View All Teachers" << endl;
        cout << "3. Enter Marks" << endl;
        cout << "4. Leave Feedback" << endl;
        cout << "5. Back" << endl;
        choice = getIntInput("\n  Enter choice (1-5): ");
        if (choice == 1)
            addTeacher();
        else if (choice == 2)
            viewAllTeachers();
        else if (choice == 3)
            enterMarks();
        else if (choice == 4)
            leaveFeedback();
        else if (choice == 5)
            return;
        else
            cout << "\n ERROR: Invalid choice!" << endl;
    }
}
                                               //Course menu
void Menu::courseMenu()
{
    int choice = 0;
    while (choice != 4) 
    {

        cout << "Course Menu"<<endl;
        cout << "1. Add Course" << endl;
        cout << "2. View All Courses" << endl;
        cout << "3. Add Venue" << endl;
        cout << "4. Back" << endl;
        choice = getIntInput("\nEnter choice (1-4): ");
        if (choice == 1)
            addCourse();
        else if (choice == 2)
            viewAllCourses();
        else if (choice == 3)
            addVenue();
        else if (choice == 4)
            return;
        else
            cout << "\nERROR: Invalid choice!" << endl;
    }
}
                                            //Schedule Menu
void Menu::scheduleMenu() {
    int choice = 0;
    while (choice != 4)
    {

        cout << "Schedule Menu"<<endl;
        cout << "1. Add Section" << endl;
        cout << "2. Generate Exam Schedule" << endl;
        cout << "3. View Schedule" << endl;
        cout << "4. Back" << endl;
        choice = getIntInput("\nEnter choice (1-4): ");
        if (choice == 1)
            addSection();
        else if (choice == 2)
            generateSchedule();
        else if (choice == 3)
            viewSchedule();
        else if (choice == 4)
            return;
        else    cout << "\nERROR: Invalid choice!" << endl;
    }
}
                                       //Main Menu
void Menu::mainMenu()
{
    int choice = 0;
    while (choice != 5) {

        cout << "Academic Management System"<<endl;
        cout << "1. Student Menu" << endl;
        cout << "2. Teacher Menu" << endl;
        cout << "3. Course Menu" << endl;
        cout << "4. Schedule Menu" << endl;
        cout << "5. Exit" << endl;
        choice = getIntInput("\nEnter choice (1-5): ");
        if (choice == 1)
            studentMenu();
        else if (choice == 2)
            teacherMenu();
        else if (choice == 3)
            courseMenu();
        else if (choice == 4)
            scheduleMenu();
        else if (choice == 5)
            cout << "\nThank You!" << endl;
        else
            cout << "\nERROR: Invalid choice! Enter 1-5." << endl;
    }
}