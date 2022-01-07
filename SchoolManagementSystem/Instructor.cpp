#include "Instructor.h"
using namespace std;

Instructor::Instructor(){
    Faculty = "";
    Department = "";
    CourseSchedule = "";
}

Instructor::Instructor(const Instructor &ı) {
    Faculty = ı.Faculty;
    Department = ı.Department;
    CourseSchedule = ı.CourseSchedule;
}

Instructor::Instructor(string n, string sn, string id, string F, string D, string C){
    setName(n);
    setSurName(sn);
    setID(id);
    Faculty = F;
    Department = D;
    CourseSchedule = C;
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

string Instructor::getCourseSchedule() {
    return CourseSchedule;
}

void Instructor::setCourseSchedule(string c) {
    CourseSchedule = c;
}

unordered_map<string, Course> Instructor::getTaughtCourses() {
    return TaughtCourses;
}

void Instructor::setTaughtCourses(unordered_map <string, Course> T) {
    TaughtCourses = T;
}

unordered_map<string, Student> Instructor::getAdvisedStudentList() {
    return AdvisedStudentList;
}

void Instructor::setAdvisedStudentList(unordered_map <string, Student> A) {
    AdvisedStudentList = A;
}

void Instructor::printTaughtCourses() {
    for(auto x: TaughtCourses){
        cout << x.first << " " << x.second << endl;
    }
}


