#include "Manager.h"
Manager::Manager(string n, string sn, string id, unordered_map<string, Instructor> I, unordered_map<string, Student> S, unordered_map<string, Course> C){
    setName(n);
    setSurName(sn);
    setID(id);
    Ins = I;
    Std = S;
    Crs = C;
}
unordered_map<string, Course> Manager::getCourse() {
    return Crs;
}

void Manager::setCourse(unordered_map<string, Course> C) {
    Crs = C;
}

unordered_map<string, Instructor> Manager::getInstructor() {
    return Ins;
}

void Manager::setInstructor(unordered_map<string, Instructor> I) {
    Ins = I;
}

unordered_map<string, Student> Manager::getStudent() {
    return Std;
}

void Manager::setStudent(unordered_map<string, Student> S) {
    std = S;
}


