#ifndef MANAGER_MANAGER_H
#define MANAGER_MANAGER_H
#include <iostream>
#include <string>
#include "User.h"
#include "Course.h"
#include "Student.h"
#include "Instructor.h"

class Manager: public User{
private:
    undordered_map<string, Student> Std;
    unordered_map<string, Instructor> Ins;
    unordered_map<string, Course> Crs;

public:
    Manager(string n, string sn, string id, unordered_map<string, Instructor> I, unordered_map<string, Student> S, unordered_map<string, Course> C);
    unordered_map<string, Instructor> getInstructor();
    void setInstructor(unordered_map<string, Instructor> I);
    unordered_map<string, Student> getStudent();
    void setStudent(unordered_map<string, Student> S);
    unoredered_map<string, Course> getCourse();
    void setCourse(unordered_map<string, Course> C);
};


#endif //MANAGER_MANAGER_H
