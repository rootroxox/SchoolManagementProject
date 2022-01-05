#include <iostream>
#include <vector>
#include <map>
#include <fstream>
#include "currıculum.h"
#include "transcript.h"
//#include "kurs.h"
using namespace std;

class Curriculum
{
   void printCurriculum()
    {
        for( auto it = courseList.begin(); it != courseList.end(); ++it )
        {
            cout << it->first;
            string& value = it->second;
            cout << " " << value << endl;
        }
    }
   void addCourseToSemester(string String, string course)
    {
        courseList.insert(String, course);
    }
    void removeCourseFromSemester(string String, string course)
    {
        courseList.erase(String, course);
    }
public:
    void Curriculum::getdepartmentName()
    {
        return departmentName;
    }
    void Curriculum::setdepartmentName(string dN)
    {
        departmentName = dN;
    }
    /*string departmentName, temp, line, coursecode, semester, coursename;
    string studentname,check;
    map<string, string> courseList;
    fstream myFilein, myFileout;
    myFilein.open("Curriculum.csv", ios::in);
    vector<string> ReadFile;
    void printCurriculum()
    {
        for (iterator = courseList.begin(); itrerator != courseList.end(); ++itrerator)
        {
            cout << itrerator->first
                 << '\t' << itrerator->second << '\n';
        }
    }
    addCourseToSemester(string course)
    {
        check = stoi(ReadFile[2]);
        course_ = stoi(course);
        if (check == course)
        {
            courseList.insert({ReadFile[2],ReadFile[1]})
            break;
        }
    }
    removeCourseFromSemester(string course)
    {
        check = stoi(ReadFile[2]);
        course_ = stoi(course);
        if (check == course)
        {
            string coursee;
           coursee = courseList.erase(course);
        }
    }

public:
    curriculum()
    {
        while (myFilein >> temp)
        {
            ReadFile.clear();
            getline(ReadFile, line);
            stringstream s(line);
            while (getline(s,departmentName,';'))
            {
                ReadFile.push_back(departmentName);
            }
            check = stoi(ReadFile[0]);
            if (check == studentname)
            {

                courseList.insert({ReadFile[2],ReadFile[1]})
                break;
            }
        }
    }*/
};
