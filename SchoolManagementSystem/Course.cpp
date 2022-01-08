//
// Created by ayber on 7.01.2022.
//

#include "Course.h"
#include <iostream>

Course::Course(const Course& obj) {
    CourseCode = obj.CourseCode;
    CourseName = obj.CourseName;
    Credit = obj.Credit;
    Semester = obj.Semester;
}

Course::Course(string courseCode, string courseName, int credit, int semester) {
    CourseCode = courseCode;
    CourseName = courseName;
    Credit = credit;
    Semester = semester;
}

Course::Course() {
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

ostream& operator<<(ostream& os, Course& course) {
    os << "Course Code: " << course.getCourseCode() << "\nCourse Name: " << course.getCourseName() << "\nCredit: "
        << course.getCredit() << endl;
    return os;
}