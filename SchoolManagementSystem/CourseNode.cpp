//
// Created by ayber on 7.01.2022.
//

#include "CourseNode.h"
#include "Course.h"

//CourseNode::CourseNode(const CourseNode &obj) {
//    course = obj.course;
//    passCredit = obj.passCredit;
//    passGrade = obj.passGrade;
//    points[5] = obj.points[5];
//    grades[5] = obj.grades[5];
//}

CourseNode::CourseNode(Course course) {
    this->course = course;
    int randomIndex = rand() % 5;
    this->passCredit = this->points[randomIndex];
    this->passGrade = this->grades[randomIndex];
}

CourseNode::CourseNode(Course course, bool isNull) {
    this->course = course;
    this->passCredit = 0.0;
    this->passGrade = "";
}

Course CourseNode::getCourse() {
    return this->course;
}

void CourseNode::setCourse(Course course) {
    this->course = course;
}

double CourseNode::getPassCredit() {
    return this->passCredit;
}

void CourseNode::setPassCredit(double passCredit) {
    this->passCredit = passCredit;
}

string CourseNode::getPassGrade() {
    return this->passGrade;
}

void CourseNode::setPassGrade(string passGrade) {
    this->passGrade = passGrade;
}