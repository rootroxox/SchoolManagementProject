#ifndef COURSE_COURSE_H
#define COURSE_COURSE_H
#include <string>
#include <iostream>
using namespace std;


class Course {
private:
    string CourseCode, CourseName;
    int Credit, Hours, Semester;
public:
    Course();
    Course(string Code, string Name, int Cr);
    string getCourseCode();
    void setCourseCode(string Code);
    string getCourseName();
    void setCourseName(string Name);
    int getCredit();
    void setCredit(int C);
    int getSemester();
    void setSemester(int S);
    friend ostream &operator <<(ostream &os, const Course Cr);
};


#endif //COURSE_COURSE_H
