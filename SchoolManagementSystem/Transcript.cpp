//
// Created by ayber on 7.01.2022.
//

#include "Transcript.h"
Transcript::Transcript() {}

vector<CourseNode> Transcript::getCompletedCourses() {
    return completedCourses;
}

void Transcript::setCompletedCourses(vector<CourseNode> completedCourses) {
    this->completedCourses = completedCourses;
}

double Transcript::getGPA() {
    return this->GPA;
}

void Transcript::setGPA(double GPA) {
    this->GPA = GPA;
}

void Transcript::updateGPA() {
    double gpa;
    double totalPointsEarned = 0.0;
    double totalCreditsAttempted = 0;

    for (CourseNode testNode : this->completedCourses) {
        totalPointsEarned += testNode.getPassCredit() * testNode.getCourse().getCredit();
        totalCreditsAttempted += testNode.getCourse().getCredit();
    }

    gpa = totalPointsEarned / totalCreditsAttempted;
    this->setGPA(gpa);
}