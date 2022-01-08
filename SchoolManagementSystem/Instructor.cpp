//
// Created by ayber on 7.01.2022.
//

#include "Instructor.h"

Instructor::Instructor(const Instructor& obj) {
    setName(obj.Name);
    setSurName(obj.SurName);
    setID(obj.ID);
    Faculty = obj.Faculty;
    Department = obj.Department;
    isAdvisor = obj.isAdvisor;
    TaughtCourses = obj.TaughtCourses;
    AdvisedStudentList = obj.AdvisedStudentList;
}

Instructor::Instructor(string name, string surname, string id, string faculty, string department, bool isAdvisor) {
    this->setName(name);
    this->setSurName(surname);
    this->setID(id);
    this->Faculty = faculty;
    this->Department = department;
    this->isAdvisor = isAdvisor;
}

Instructor::Instructor() {

}

bool Instructor::getIsAdvisor() {
    return isAdvisor;
}

void Instructor::setIsAdvisor(bool I) {
    isAdvisor = I;
}

string Instructor::getFaculty() {
    return Faculty;
}

void Instructor::setFaculty(string f) {
    Faculty = f;
}

string Instructor::getDepartment() {
    return Department;
}

void Instructor::setDepartment(string d) {
    Department = d;
}

map<string, Course> Instructor::getTaughtCourses() {
    return TaughtCourses;
}

void Instructor::setTaughtCourses(map <string, Course> T) {
    TaughtCourses = T;
}

map<string, Student> Instructor::getAdvisedStudentList() {
    return AdvisedStudentList;
}

void Instructor::setAdvisedStudentList(map <string, Student> A) {
    AdvisedStudentList = A;
}

ostream& operator<<(ostream& si, Instructor& instructor) {
    si << "Name: " << instructor.getName() << "\nSurname: " << instructor.getSurName() << "\nID: "
        << instructor.getID() << "\nFaculty: " << instructor.getFaculty() << "\nDepartment: " << instructor.getDepartment() << endl;
    return si;
}

void Instructor::showToughtCourses(Instructor instructor) {
    map<string,Course> taught = instructor.getTaughtCourses();
    map<string, Course>::iterator it;

    system("cls");
    for (it = taught.begin(); it != taught.end(); it++)
    {
        cout << "Course Code: " << it->second.getCourseCode() << "\nCourse Name: " << it->second.getCourseName() << "\n" << endl;
    }
}