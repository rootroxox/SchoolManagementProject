#include "Manager.h"

Manager::Manager(const string& n, const string& s, const string& ı, const map<string, Student>& studentList,
    const map<string, Instructor>& instructorList, const map<string, Course>& courseList) : User(n, s, ı),
    studentList(
        studentList),
    instructorList(
        instructorList),
    courseList(
        courseList) {}

const map<string, Student>& Manager::getStudentList() const {
    return studentList;
}

void Manager::setStudentList(const map<string, Student>& studentList) {
    Manager::studentList = studentList;
}

const map<string, Instructor>& Manager::getInstructorList() const {
    return instructorList;
}

void Manager::setInstructorList(const map<string, Instructor>& instructorList) {
    Manager::instructorList = instructorList;
}

const map<string, Course>& Manager::getCourseList() const {
    return courseList;
}

void Manager::setCourseList(const map<string, Course>& courseList) {
    Manager::courseList = courseList;
}

ostream& operator<<(ostream& os, Manager& manager) {
    system("cls");
    os << "Name: " << manager.getName() << "\nSurname: " << manager.getSurName() << "\nID: "
        << manager.getID() << endl;
    return os;
}

void Manager::showInstructorsMap(Manager manager) {
    map<string, Instructor> instructors = manager.getInstructorList();
    map<string, Instructor>::iterator it;

    system("cls");
    for (it = instructors.begin(); it != instructors.end(); it++)
    {
        cout << it->second << endl;
    }
}

void Manager::showStudentMap(Manager manager) {
    map<string, Student> students = manager.getStudentList();
    map<string, Student>::iterator it;

    system("cls");
    for (it = students.begin(); it != students.end(); it++)
    {
        cout << it->second << endl;
    }
}

void Manager::showCourseList(Manager manager) {
    map<string, Course> courses = manager.getCourseList();
    map<string, Course>::iterator it;

    system("cls");
    for (it = courses.begin(); it != courses.end(); it++)
    {
        cout << it->second << endl;
    }
}