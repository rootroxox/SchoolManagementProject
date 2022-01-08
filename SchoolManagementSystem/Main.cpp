#include <iostream>
#include <fstream>
#include <sstream>
#include "Student.h"
#include "Manager.h"
#include "Instructor.h"
#include <map>
#include <stdlib.h>

using namespace std;

map<string, Student> createStudentMap(string studentFileName);
map<string, Student> studentMap;
map<string, Instructor> instructorMap;
map<string, Course> courseMap;
map<string, Manager> managerMap;
map<string, vector<Course>> curriculumMap;

void studentMenu();
void instructorMenu();
void managerMenu();
void loginMenu();
bool login(int type);
bool checkStudent(map<string, Student> m, string key);
bool checkInstructor(map<string, Instructor> m, string key);
bool checkManager(map<string, Manager> m, string key);
void setInstructorsTaughtCourses();
map<string, Manager> createManagerMap(string managersFile);
map<string, Course> createCourseMap(string coursesFile);
map<string, Instructor> createInstructorMap(string instructorsFile);

int main() {
    instructorMap = createInstructorMap("Instructors.csv");
    courseMap = createCourseMap("Curriculum.csv");
    studentMap = createStudentMap("Students.csv");
    managerMap = createManagerMap("Managers.csv");
    setInstructorsTaughtCourses();

    loginMenu();
    return 0;
}

void setInstructorsTaughtCourses() {
    for (auto it = curriculumMap.begin(); it != curriculumMap.end(); it++) {
        string department = it->first;
        Instructor instructorsOfSameDepartment[2];

        int j = 0;
        for (auto itr = instructorMap.begin(); itr != instructorMap.end(); itr++) {
            Instructor instructor = itr->second;
            if (instructor.getDepartment() == department) {
                instructorsOfSameDepartment[j] = instructor;
                j++;
                if (j == 2)
                    break;
            }
        }

        for (int i = 0; i < curriculumMap.at(department).size(); i++) {
            if (i < curriculumMap.at(department).size() / 2) {
                map<string, Course> taught = instructorsOfSameDepartment[0].getTaughtCourses();
                taught.insert({ curriculumMap.at(department)[i].getCourseCode(), curriculumMap.at(department)[i] });
                instructorsOfSameDepartment[0].setTaughtCourses(taught);
            }
            else {
                map<string, Course> taught = instructorsOfSameDepartment[1].getTaughtCourses();
                taught.insert({ curriculumMap.at(department)[i].getCourseCode(), curriculumMap.at(department)[i] });
                instructorsOfSameDepartment[1].setTaughtCourses(taught);
            }
        }
        instructorMap.erase(instructorsOfSameDepartment[0].ID);
        instructorMap.erase(instructorsOfSameDepartment[1].ID);
        instructorMap.insert(make_pair(instructorsOfSameDepartment[0].ID, instructorsOfSameDepartment[0]));
        instructorMap.insert(make_pair(instructorsOfSameDepartment[1].ID, instructorsOfSameDepartment[1]));
    }
}

map<string, Manager> createManagerMap(string managersFile) {
    map<string, Manager> myManagerList;

    ifstream managerFile(managersFile);
    if (!managerFile.is_open())
        cout << "Error: Cannot open file!" << endl;

    string line;
    getline(managerFile, line);
    vector<string> values;

    while (getline(managerFile, line)) {
        stringstream ss(line);

        while (ss.good()) {
            string substr;
            getline(ss, substr, ';');
            values.push_back(substr);
        }

        string name = values[0];
        string surname = values[1];
        string id = values[2];

        Manager manager(name, surname, id, studentMap, instructorMap, courseMap);
        myManagerList.insert(make_pair(manager.getID(), manager));
        values.clear();
    }

    return myManagerList;
}

map<string, Course> createCourseMap(string coursesFile) {
    map<string, Course> myCourseList;
    vector<Course> myFakeCourseList;

    ifstream courseFile(coursesFile);
    if (!courseFile.is_open())
        cout << "Error: Cannot open file!" << endl;

    string line;
    getline(courseFile, line);
    vector<string> values;

    string oldDepartment = "X";

    while (getline(courseFile, line)) {
        stringstream ss(line);

        while (ss.good()) {
            string substr;
            getline(ss, substr, ';');
            values.push_back(substr);
        }

        string department = values[0];
        string semester = values[1];
        string courseCode = values[2];
        string courseName = values[3];
        string credit = values[4];

        Course course(courseCode, courseName, stoi(credit), stoi(semester));
        myCourseList.insert({ course.getCourseCode(), course });

        if (!(department == oldDepartment) && !(oldDepartment == "X")) {
            myFakeCourseList.clear();
        }
        myFakeCourseList.push_back(course);
        curriculumMap.erase(department);
        curriculumMap.insert(make_pair(department, myFakeCourseList));

        oldDepartment = department;
        values.clear();
    }

    return myCourseList;
}

map<string, Instructor> createInstructorMap(string instructorsFile) {
    map<string, Instructor> myInstructorList;

    ifstream instructorFile(instructorsFile);
    if (!instructorFile.is_open())
        cout << "Error: Cannot open file!" << endl;

    string line;
    getline(instructorFile, line);
    vector<string> values;

    while (getline(instructorFile, line)) {
        stringstream ss(line);

        while (ss.good()) {
            string substr;
            getline(ss, substr, ';');
            values.push_back(substr);
        }

        string name = values[0];
        string surname = values[1];
        string ID = values[2];
        string faculty = values[3];
        string department = values[4];
        bool isAdvisor = false;
        if (stoi(values[5]) == 1)
            isAdvisor = true;

        Instructor instructor(name, surname, ID, faculty, department, isAdvisor);
        myInstructorList.insert(make_pair(ID, instructor));
        values.clear();
    }

    return myInstructorList;
}

map<string, Student> createStudentMap(string studentFileName) {
    map<string, Student> myStudentList;

    ifstream studentFile(studentFileName);
    if (!studentFile.is_open())
        cout << "Error: Cannot open file!" << endl;

    string line;
    getline(studentFile, line);
    vector<string> values;

    while (getline(studentFile, line)) {
        stringstream ss(line);

        while (ss.good()) {
            string substr;
            getline(ss, substr, ';');
            values.push_back(substr);
        }

        string name = values[0];
        string surname = values[1];
        string ID = values[2];
        int classLevel = stoi(values[3]);
        string faculty = values[4];
        string department = values[5];
        string advisorID = values[6];

        Student student(name, surname, ID, classLevel, faculty, department); //, instructorMap.at(advisorID)
        student.setCurriculum(curriculumMap.at(department));

        map<string, Student> newAdvisedStudentList = instructorMap.at(advisorID).getAdvisedStudentList();
        newAdvisedStudentList.insert({ student.ID,student });
        instructorMap.at(advisorID).setAdvisedStudentList(newAdvisedStudentList);

        for (int i = 0; i < curriculumMap.at(department).size(); i++) {
            if (curriculumMap.at(department)[i].getSemester() < classLevel * 2) {
                vector<CourseNode> studentsCompletedCourses = student.getTranscript().getCompletedCourses();
                studentsCompletedCourses.push_back(CourseNode(curriculumMap.at(department)[i]));

                Transcript studentTranscript = student.getTranscript();
                studentTranscript.setCompletedCourses(studentsCompletedCourses);
                studentTranscript.updateGPA();
                student.setTranscript(studentTranscript);
            }

            if (curriculumMap.at(department)[i].getSemester() == classLevel * 2) {
                vector<CourseNode> studentTakenCourses = student.getTakenCourses();
                studentTakenCourses.push_back(CourseNode(curriculumMap.at(department)[i], true));
                student.setTakenCourses(studentTakenCourses);
            }
        }
        pair<string, Student> myStudentX(student.ID, student);
        myStudentList.insert(myStudentX);
        values.clear();
    }
    return myStudentList;
}

string studentID;
string instructorID;
string managerID;

void loginMenu() {
    system("cls");
    int choice;

    cout << "1. Student Login" << endl;
    cout << "2. Instructor Login" << endl;
    cout << "3. ManagerLogin" << endl;
    cout << "4. Exit" << endl;
    cout << "Choice: ";

    cin >> choice;
    bool isSuccesfull = false;

    switch (choice) {
    case 1:
        isSuccesfull = login(1);
        system("cls");
        if (isSuccesfull) {
            system("cls");
            studentMenu();
        }
        else {
            cout << "Wrong ID or Password!" << endl;
            system("cls");
            loginMenu();
        }
        break;
    case 2:
        isSuccesfull = login(2);
        system("cls");
        if (isSuccesfull) {
            system("cls");
            instructorMenu();
        }
        else {
            cout << "Wrong ID or Password!" << endl;
            system("cls");
            loginMenu();
        }
        break;
    case 3:
        isSuccesfull = login(3);
        system("cls");
        if (isSuccesfull) {
            system("cls");
            managerMenu();
        }
        else {
            cout << "Wrong ID or Password!" << endl;
            system("cls");
            loginMenu();
        }
        break;
    case 4:
        exit(-1);
        break;
    default:
        cout << "Wrong Input!" << endl;
        system("cls");
        loginMenu();
        break;
    }
}

bool login(int type) {
    string id, passwd;

    cout << "Enter your ID: ";
    cin >> id;
    
    cout << "Enter your password: ";
    cin >> passwd;
    string correctPasswd;

    switch (type) {
    case 1:    
        correctPasswd = "s" + id;
        if (passwd == correctPasswd && checkStudent(studentMap, id)) {
            cout << "Login Succesfull!" << endl;
            studentID = id;
            return true;
        }
        return false;
        break;
    case 2:
        correctPasswd = "i" + id;
        if (passwd == correctPasswd && checkInstructor(instructorMap, id)) {
            cout << "Login Succesfull!" << endl;
            instructorID = id;
            return true;
        }
        return false;
        break;
    case 3:
        correctPasswd = "m" + id;
        if (passwd == correctPasswd && checkManager(managerMap, id)) {
            cout << "Login Succesfull!" << endl;
            managerID = id;
            return true;
        }
        return false;
        break;
    }
}

bool checkStudent(map<string, Student> m, string key)
{
    if (m.find(key) == m.end())
        return false;

    return true;
}

bool checkInstructor(map<string, Instructor> m, string key)
{
    if (m.find(key) == m.end())
        return false;

    return true;
}

bool checkManager(map<string, Manager> m, string key)
{
    if (m.find(key) == m.end())
        return false;

    return true;
}

void studentMenu() {
    cout << "*************************************************" << endl;
    cout << "1. Show Info" << endl;
    cout << "2. Show Transcript" << endl;
    cout << "3. Show Curriculum" << endl;
    cout << "4. Show Taken Courses" << endl;
    cout << "5. Back" << endl;
    cout << "Choice: ";

    int choice;
    cin >> choice;
    cout << "-------------------------------------------------" << endl;
    switch (choice) {
    case 1:
        system("cls");
        cout << studentMap.at(studentID) << endl;
        studentMenu();
        break;
    case 2:
        studentMap.at(studentID).showTranscript(studentMap.at(studentID));
        studentMenu();
        break;
    case 3:
        studentMap.at(studentID).showCurriculum(studentMap.at(studentID));
        studentMenu();
        break;
    case 4:
        studentMap.at(studentID).showTakenCourses(studentMap.at(studentID));
        studentMenu();
        break;
    case 5:
        loginMenu();
        break;
    default:
        cout << "Wrong Input!" << endl;
        studentMenu();
        break;
    }
}

void instructorMenu() {
    cout << "*************************************************" << endl;
    cout << "1. Show Info" << endl;
    cout << "2. Show Taught Courses" << endl;
    cout << "3. Back" << endl;
    cout << "Choice: ";
    
    int choice;
    cin >> choice;

    cout << "-------------------------------------------------" << endl;
    switch (choice) {
    case 1:
        system("cls");
        cout << instructorMap.at(instructorID) << endl;
        instructorMenu();
        break;
    case 2:
        instructorMap.at(instructorID).showToughtCourses(instructorMap.at(instructorID));
        instructorMenu();
        break;
    case 3:
        loginMenu();
        break;
    default:
        cout << "Wrong Input!" << endl;
        instructorMenu();
        break;
    }
}

void managerMenu() {
    cout << "*************************************************" << endl;
    cout << "1. Show Info" << endl;
    cout << "2. Show Instructor List" << endl;
    cout << "3. Show Student List" << endl;
    cout << "4. Show Course List" << endl;
    cout << "5. Back" << endl;
    cout << "Choice: ";

    int choice;
    cin >> choice;

    switch (choice) {
    case 1:
        cout << managerMap.at(managerID) << endl;
        managerMenu();
        break;
    case 2:
        managerMap.at(managerID).showInstructorsMap(managerMap.at(managerID));
        managerMenu();
        break;
    case 3:
        managerMap.at(managerID).showStudentMap(managerMap.at(managerID));
        managerMenu();
        break;
    case 4:
        managerMap.at(managerID).showCourseList(managerMap.at(managerID));
        managerMenu();
        break;
    case 5:
        loginMenu();
        break;
    default:
        break;
    }
}