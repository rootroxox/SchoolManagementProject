//
// Created by ayber on 7.01.2022.
//

#ifndef XX_INSTRUCTOR_H
#define XX_INSTRUCTOR_H
#include <string>
#include "Course.h"
#include "map"
#include "User.h"
#include "Student.h"
using namespace std;


class Instructor : public User {
private:
    string Faculty, Department;
    bool isAdvisor;
    map<string, Course> TaughtCourses;
    map<string, Student> AdvisedStudentList;
public:
    Instructor(const Instructor& obj);
    Instructor(string name, string surname, string id, string faculty, string department, bool isAdvisor);
    Instructor();

    Instructor(const string& n, const string& s, const string& ý, const string& faculty, const string& department,
        bool isAdvisor, const map<string, Course>& taughtCourses,
        const map<string, Student>& advisedStudentList);

    bool getIsAdvisor();
    void setIsAdvisor(bool isAdvisor);
    string getFaculty();
    void setFaculty(string faculty);
    string getDepartment();
    void setDepartment(string department);
    map<string, Course> getTaughtCourses();
    void setTaughtCourses(map<string, Course> taughtCourses);
    map<string, Student> getAdvisedStudentList();
    void setAdvisedStudentList(map<string, Student> advisedStudentList);
    void showToughtCourses(Instructor instructor);
    friend ostream& operator<<(ostream& si, Instructor& instructor);
};


#endif //XX_INSTRUCTOR_H
