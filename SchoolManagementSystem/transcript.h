#ifndef SCHOOLMANAGEMENT_TRANSCRIPT_H
#define SCHOOLMANAGEMENT_TRANSCRIPT_H

using namespace std;
class Transcript
        {
    map<string, string> completedCourses;
    double gpa;
public:
            Transcript();
            Transcript(double gpa_, string course, string grade);
            double getgpa();
            setgpa(double gpa_);
};



#endif //SCHOOLMANAGEMENT_TRANSCRIPT_H
