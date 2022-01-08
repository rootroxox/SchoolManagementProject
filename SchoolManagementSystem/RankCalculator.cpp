//
// Created by ayber on 7.01.2022.
//

#include "RankCalculator.h"
RankCalculator::RankCalculator(map<string, Student> studentList, map<string, vector<Course>> curriculumList) {
    this->studentList = studentList;
    this->curriculumList = curriculumList;
}

map<string, Student> RankCalculator::updateRanks() {
    for (auto it = this->curriculumList.begin(); it != this->curriculumList.end(); it++) {
        RankCalculator::updateRanksOfStudents(it->first);
    }
    return this->studentList;
}

void RankCalculator::updateRanksOfStudents(string department) {
    vector<Student> departmentStudent;

    for (auto it = this->studentList.begin(); it != this->studentList.end(); it++) {
        if (it->second.getDepartment() == department) {
            departmentStudent.push_back(it->second);
        }
    }

    RankCalculator::bubbleSort(departmentStudent);
    for (int i = 0; i < departmentStudent.size(); i++) {
        Student x = studentList.at(departmentStudent[i].getID());
        x.setRank(departmentStudent.size() - i);
        pair<std::string, Student> myStudent(x.getID(), x);
        studentList.insert(myStudent);
    }
}

void RankCalculator::bubbleSort(vector<Student> studentArrayList) {
    int n = studentArrayList.size();
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (studentArrayList[j].getGPA() > studentArrayList[j + 1].getGPA()) {
                Student temp = studentArrayList[j];
                studentArrayList[j] = studentArrayList[j + 1];
                studentArrayList[j + 1] = temp;
            }
        }
    }
}

