//
// Created by ayber on 7.01.2022.
//

#ifndef XX_STUDENT_H
#define XX_STUDENT_H
#include <string>
#include <vector>
#include "User.h"
#include "Transcript.h"
#include <iostream>

using namespace std;
class Student : public User {
private:
    double GPA;
    int classLevel;
    string faculty;
    string department;
    int rank;
    Transcript transcript;
    vector<Course> curriculum;
    vector<CourseNode> takenCourses;

public:
    Student();
    Student(string name, string surname, string iD, int classLevel, string faculty, string department); //Instructor kaldýrdýk
    Student(const Student& obj);
    void setGPA(double gpa);
    double getGPA();
    void setClassLevel(int classLevel);
    int getClassLevel();
    void setFaculty(string faculty);
    string getFaculty();
    void setDepartment(string department);
    string getDepartment();
    //void setAdvisor(Instructor advisor);
    //Instructor getAdvisor();
    void setRank(int);
    int getRank();
    Transcript getTranscript();
    void setCurriculum(vector<Course> curriculum);
    vector<Course> getCurriculum();
    vector<CourseNode> getTakenCourses();
    void setTakenCourses(vector<CourseNode> takenCourses);
    void setTranscript(Transcript transcript);
    void showTranscript(Student student);
    void showCurriculum(Student student);
    void showTakenCourses(Student student);
    vector<CourseNode> sortVector(vector<CourseNode> transcriptCourses);
    vector<Course> sortVector(vector<Course> transcriptCourses);
    void swap(CourseNode* xp, CourseNode* yp);
    void swap(Course* xp, Course* yp);
    void bubbleSort(vector<CourseNode> courseNodeList, int n);    
    void bubbleSort(vector<Course> courseNodeList, int n);
    friend ostream& operator<<(ostream& si, const Student& student);
    //friend ostream& operator<<(ostream& sc, const Student& student);
    friend ostream& operator<<(ostream& stc, const Student& student);
};


#endif //XX_STUDENT_H
