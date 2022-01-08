//
// Created by ayber on 7.01.2022.
//

#include "Student.h"
#include "CourseNode.h"
#include "Transcript.h"
#include "User.h"
#include "Instructor.h"
#include <iostream>
#include <iomanip>

Student::Student() {

}

Student::Student(const Student& obj) {
    this->setName(obj.Name);
    this->setSurName(obj.SurName);
    this->setID(obj.ID);
    GPA = obj.GPA;
    department = obj.department;
    classLevel = obj.classLevel;
    faculty = obj.faculty;
    rank = obj.rank;
    transcript = obj.transcript;
    curriculum = obj.curriculum;
    takenCourses = obj.takenCourses;
}

Student::Student(string name, string surname, string ID, int classLevel, string faculty, string department) { //Instructor kaldýrdýk
    this->setName(name);
    this->setSurName(surname);
    this->setID(ID);
    this->classLevel = classLevel;
    this->faculty = faculty;
    this->department = department;
    //    this->advisor = advisor;
}

void Student::setGPA(double GPA) {
    this->GPA = GPA;
}

double Student::getGPA() {
    return this->GPA;
}

void Student::setClassLevel(int classLevel) {
    this->classLevel = classLevel;
}

int Student::getClassLevel() {
    return this->classLevel;
}

void Student::setFaculty(std::string faculty) {
    this->faculty = faculty;
}

std::string Student::getFaculty() {
    return this->faculty;
}

void Student::setDepartment(std::string department) {
    this->department = department;
}

std::string Student::getDepartment() {
    return this->department;
}

//void Student::setAdvisor(Instructor advisor) {
//    this->advisor = advisor;
//}
//
//Instructor Student::getAdvisor() {
//    return this->advisor;
//}

void Student::setRank(int rank) {
    this->rank = rank;
}

int Student::getRank() {
    return this->rank;
}

void Student::setTranscript(Transcript transcript) {
    this->setGPA(this->transcript.getGPA());
    this->transcript = transcript;
}

Transcript Student::getTranscript() {
    return this->transcript;
}

void Student::setCurriculum(vector<Course> curriculum) {
    this->curriculum = curriculum;
}

vector<Course> Student::getCurriculum() {
    return this->curriculum;
}

void Student::setTakenCourses(vector<CourseNode> takenCourses) {
    this->takenCourses = takenCourses;
}

vector<CourseNode> Student::getTakenCourses() {
    return this->takenCourses;
}

ostream& operator<<(ostream& si, const Student& student) {
    si << "Name: " << student.Name << "\nSurname: " << student.SurName << "\nID: "
        << student.ID << "\nClass: " << student.classLevel << "\nFaculty: "
        << student.faculty << "\nDepartment: " << student.department << endl;
    return si;
}


void Student::showCurriculum(Student student) {
    vector<Course> transcriptCourses = student.getCurriculum();
    vector<Course> sorted = student.sortVector(transcriptCourses);

    int defaultSemester = 1;
    int oldSemester = 1;

    system("cls");
    cout << "Semester : " << 1 << endl;
    for (int i = 0; i < sorted.size(); i++) {
        cout << "\n";
        int semester = sorted[i].getSemester();

        if (semester == defaultSemester || semester == oldSemester) {
            cout << "Course Code: " << sorted[i].getCourseCode() << "\nCourse Name: " << sorted[i].getCourseName()
                << "\nCourse Credit: " << sorted[i].getCredit() << endl;
        }
        else {
            cout << "-------------------------------------------------------------" << endl;
            cout << "Semester : " << semester << endl;
            cout << "Course Code: " << sorted[i].getCourseCode() << "\nCourse Name: " << sorted[i].getCourseName()
                << "\nCourse Credit: " << sorted[i].getCredit() << endl;
        }

        oldSemester = semester;
    }
}

void Student::showTakenCourses(Student student) {
    vector<CourseNode> takenCourses = student.getTakenCourses();

    system("cls");
    for (int i = 0; i < takenCourses.size(); i++) {
        cout << "Course Code: " << takenCourses[i].getCourse().getCourseCode() << "\nCourse Name: " << takenCourses[i].getCourse().getCourseName()
             << "\nCourse Credit: " << takenCourses[i].getCourse().getCredit() << endl;
        cout << "-------------------------------------------------------------" << endl;
    }
}

//ostream& operator<<(ostream & sc, Student & student) {
//    vector<Course> transcriptCourses = student.getCurriculum();
//    vector<Course> sorted = student.sortVector(transcriptCourses);
//
//    int defaultSemester = 1;
//    int oldSemester = 1;
//
//    system("cls");
//    sc << "Semester : " << 1 << endl;
//    for (int i = 0; i < sorted.size(); i++) {
//        sc << "\n";
//        int semester = sorted[i].getSemester();
//
//        if (semester == defaultSemester || semester == oldSemester) {
//            sc << "Course Code: " << sorted[i].getCourseCode() << "\nCourse Name: " << sorted[i].getCourseName()
//                << "\nCourse Credit: " << sorted[i].getCredit() << endl;
//        }
//        else {
//            sc << "-------------------------------------------------------------" << endl;
//            sc << "Semester : " << semester << endl;
//            sc << "Course Code: " << sorted[i].getCourseCode() << "\nCourse Name: " << sorted[i].getCourseName()
//                << "\nCourse Credit: " << sorted[i].getCredit() << endl;
//        }
//
//        oldSemester = semester;
//    }
//
//    sc << "\nGPA: " << setprecision(3) << student.getGPA() << "\n" << endl;
//
//    return sc;
//}

void Student::showTranscript(Student student) {
    vector<CourseNode> transcriptCourses = student.getTranscript().getCompletedCourses();
    vector<CourseNode> sorted = student.sortVector(transcriptCourses);

    int defaultSemester = 1;
    int oldSemester = 1;

    system("cls");
    cout << "Semester : " << 1 << endl;
    for (int i = 0; i < sorted.size(); i++) {
        cout << "\n";
        int semester = sorted[i].getCourse().getSemester();

        if (semester == defaultSemester || semester == oldSemester) {
            cout << "Course Code: " << sorted[i].getCourse().getCourseCode() << "\nCourse Name: " << sorted[i].getCourse().getCourseName()
                << "\nCourse Credit: " << sorted[i].getCourse().getCredit() << "\nPass Grade: " << sorted[i].getPassGrade() << endl;
        }
        else {
            cout << "-------------------------------------------------------------" << endl;
            cout << "Semester : " << semester << endl;
            cout << "Course Code: " << sorted[i].getCourse().getCourseCode() << "\nCourse Name: " << sorted[i].getCourse().getCourseName()
                << "\nCourse Credit: " << sorted[i].getCourse().getCredit() << "\nPass Grade: " << sorted[i].getPassGrade() << endl;
        }
        
        oldSemester = semester;
    }

    cout << "\nGPA: " << setprecision(3) << student.getGPA() << "\n" << endl;
}

vector<CourseNode> Student::sortVector(vector<CourseNode> transcriptCourses) {
    bubbleSort(transcriptCourses, transcriptCourses.size());

    return transcriptCourses;

}

vector<Course> Student::sortVector(vector<Course> transcriptCourses) {
    bubbleSort(transcriptCourses, transcriptCourses.size());

    return transcriptCourses;

}

void Student::swap(CourseNode* xp, CourseNode* yp)
{
    CourseNode temp = *xp;
    *xp = *yp;
    *yp = temp;
}

void Student::bubbleSort(vector<CourseNode> courseNodeList, int n)
{
    int i, j;
    for (i = 0; i < n - 1; i++)
        for (j = 0; j < n - i - 1; j++)
            if (courseNodeList[j].getCourse().getSemester() > courseNodeList[j+1].getCourse().getSemester())
                swap(&courseNodeList[j], &courseNodeList[j+1]);
}

void Student::bubbleSort(vector<Course> courseNodeList, int n)
{
    int i, j;
    for (i = 0; i < n - 1; i++)
        for (j = 0; j < n - i - 1; j++)
            if (courseNodeList[j].getSemester() > courseNodeList[j + 1].getSemester())
                swap(&courseNodeList[j], &courseNodeList[j + 1]);
}

void Student::swap(Course* xp, Course* yp)
{
    Course temp = *xp;
    *xp = *yp;
    *yp = temp;
}