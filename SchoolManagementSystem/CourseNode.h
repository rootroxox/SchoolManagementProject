//
// Created by ayber on 7.01.2022.
//

#ifndef XX_COURSENODE_H
#define XX_COURSENODE_H

#include "Course.h"

class CourseNode {
private:
    Course course;
    double passCredit;
    string passGrade;
    double points[5] = { 4.0,3.5,3.0,2.5,2.0 };
    string grades[5] = { "AA","BA","BB","CB","CC" };
public:
    explicit CourseNode(Course course);
    CourseNode(Course course, bool isNull);
    //CourseNode(const CourseNode &obj);
    Course getCourse();
    void setCourse(Course course);
    double getPassCredit();
    void setPassCredit(double passCredit);
    string getPassGrade();
    void setPassGrade(string passGrade);
};


#endif //XX_COURSENODE_H
