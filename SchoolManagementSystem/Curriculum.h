//
// Created by ayber on 7.01.2022.
//

#ifndef XX_CURRICULUM_H
#define XX_CURRICULUM_H
#include <string>
#include "Course.h"
#include <map>
using namespace std;

class Curriculum {
private:
    string department;
    map<string, map<string, Course>> courseMap;
public:
    Curriculum(string department, map<string, map<string, Course>> courseMap);
    Curriculum(const Curriculum& obj);
    string getDepartment();
    void setDepartment(string department);
    map<string, map<string, Course>> getCourseMap();
    void setCourseMap(map<string, map<string, Course>> courseMap);
};

#endif //XX_CURRICULUM_H
