#ifndef SCHOOLMANAGEMENT_CURRICULUM_H
#define SCHOOLMANAGEMENT_CURRICULUM_H
#include <string>
using namespace std;

class Curriculum
{
    string departmentName;
    map<string, string> courseList;
public:
    Curriculum();
    Curriculum(string dN, string course, string semester);
    string getdepartmentName();
    setdepartmentName(string dN);

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
    }
*/


};

#endif //SCHOOLMANAGEMENT_CURRICULUM_H
