//
// Created by ayber on 7.01.2022.
//

#include "Curriculum.h"
#include <map>

Curriculum::Curriculum(const Curriculum& obj) {
    department = obj.department;
    courseMap = obj.courseMap;
}

Curriculum::Curriculum(string department, map<string, map<string, Course>> courseMap) {
    this->department = department;
    this->courseMap = courseMap;
}

string Curriculum::getDepartment() {
    return this->department;
}

void Curriculum::setDepartment(string department) {
    this->department = department;
}

map<string, map<string, Course>> Curriculum::getCourseMap() {
    return this->courseMap;
}

void Curriculum::setCourseMap(map<string, map<string, Course>> courseMap) {
    this->courseMap = courseMap;
}
