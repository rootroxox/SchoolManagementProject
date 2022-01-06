#ifndef INSTRUCTOR_INSTRUCTOR_H
#define INSTRUCTOR_INSTRUCTOR_H
#include <iostream>
#include <string>
#include <unordered_map>
#include "Course.h"
#include "User.h"
#include "Student.h"
using namespace std;

class Instructor:virtual public User {
private:
    string Faculty, Department, CourseSchedule;
    bool isAdvisor;
    unordered_map<string, Course> TaughtCourses;
    unordered_map<string, Student> AdvisedStudentList;
public:
    Instructor();
    Instructor(const Instructor &ı);
    Instructor(string n, string sn, string id, string F, string D, string C, unordered_map <string, Course> T, unordered_map <string, Student> A);
    bool getIsAdvisor();
    void setIsAdvisor(bool I);
    string getFaculty();
    void setFaculty(string f);
    string getDepartment();
    void setDepartment(string d);
    string getCourseSchedule();
    void setCourseSchedule(string c);
    unordered_map<string, Course> getTaughtCourses();
    void setTaughtCourses(unordered_map<string, Course> T);
    unordered_map<string, Student> getAdvisedStudentList();
    void setAdvisedStudentList(unordered_map<string, Student> A);
    void printTaughtCourses();
};



#endif //INSTRUCTOR_INSTRUCTOR_H
