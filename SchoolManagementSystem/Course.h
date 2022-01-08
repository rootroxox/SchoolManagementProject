//
// Created by ayber on 7.01.2022.
//

#ifndef XX_COURSE_H
#define XX_COURSE_H
#include <string>
using namespace std;


class Course {
private:
    string CourseCode, CourseName;
    int Credit, Semester;
public:
    Course(string courseCode, string courseName, int credit, int semester);
    Course();
    Course(const Course& obj);
    string getCourseCode();
    void setCourseCode(string Code);
    string getCourseName();
    void setCourseName(string Name);
    int getCredit();
    void setCredit(int C);
    int getSemester();
    void setSemester(int S);
    friend ostream& operator<<(ostream& os, Course& course);
};


#endif //XX_COURSE_H
