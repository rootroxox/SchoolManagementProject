#include "Course.h"

Course::Course() {
    CourseName = "";
    CourseCode = "";
    Credit = 0;
}

Course::Course(string Code, string Name, int Cr) {
    CourseCode = Code;
    CourseName = Name;
    Credit = Cr;
}

string Course::getCourseCode() {
    return CourseCode;
}

void Course::setCourseCode(string Code) {
    CourseCode = Code;
}

string Course::getCourseName() {
    return CourseName;
}

void Course::setCourseName(string Name) {
    CourseName = Name;
}

int Course::getCredit() {
    return Credit;
}

void Course::setCredit(int C) {
    Credit = C;
}

int Course::getSemester() {
    return Semester;
}

void Course::setSemester(int S) {
    Semester = S;
}