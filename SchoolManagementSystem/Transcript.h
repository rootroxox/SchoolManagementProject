//
// Created by ayber on 7.01.2022.
//

#ifndef XX_TRANSCRIPT_H
#define XX_TRANSCRIPT_H
#include "CourseNode.h"
#include <vector>

class Transcript
{
private:
    vector<CourseNode> completedCourses;
    double GPA;
public:
    Transcript();
    vector<CourseNode> getCompletedCourses();
    void setCompletedCourses(vector<CourseNode> completedCourses);
    double getGPA();
    void setGPA(double GPA);
    void updateGPA();
};


#endif //XX_TRANSCRIPT_H
