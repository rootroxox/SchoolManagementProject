#ifndef XX_MANAGER_H
#define XX_MANAGER_H

#include <string>
#include "User.h"
#include "Student.h"
#include "Instructor.h"
#include "Course.h"
#include <map>

using namespace std;

class Manager : public User {
private:
    map<string, Student> studentList;
    map<string, Instructor> instructorList;
    map<string, Course> courseList;

public:

    Manager(const string& n, const string& s, const string& ý, const map<string, Student>& studentList,
        const map<string, Instructor>& instructorList, const map<string, Course>& courseList);
    const map<string, Student>& getStudentList() const;
    void setStudentList(const map<string, Student>& studentList);
    const map<string, Instructor>& getInstructorList() const;
    void setInstructorList(const map<string, Instructor>& instructorList);
    const map<string, Course>& getCourseList() const;
    void setCourseList(const map<string, Course>& courseList);
    void showInstructorsMap(Manager manager);
    void showStudentMap(Manager manager);
    void showCourseList(Manager manager);
    friend ostream& operator<<(ostream& os, Manager& manager);
};

#endif //XX_MANAGER_H
