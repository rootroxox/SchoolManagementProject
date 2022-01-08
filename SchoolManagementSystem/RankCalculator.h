//
// Created by ayber on 7.01.2022.
//

#ifndef XX_RANKCALCULATOR_H
#define XX_RANKCALCULATOR_H
#include <string>
#include "Student.h"
#include "Course.h"
#include "map"
#include <vector>
using namespace std;

class RankCalculator {
private:
    map<string, Student> studentList;
    map<string, vector<Course>> curriculumList;
public:
    RankCalculator(map<string, Student> studentList, map<string, vector<Course>> curriculumList);
    map<string, Student> updateRanks();
    void updateRanksOfStudents(string department);
    static void bubbleSort(vector<Student> studentVector);
};


#endif //XX_RANKCALCULATOR_H
