#include "iostream"
#include "currıculum.h"
#include "transcript.h"
using namespace std;

class Transcript
{
    transcript::Transcript()
    {
        gpa = "";
    }
    transcript::Transcript(double gpa_)
    {
        gpa = gpa_;
    }

    double calculateGpa()
    {
        double point = 0;
        double count = 0;
        for (it = completedCourses.begin(); it != completedCourses.end(); ++it)
        {
            if (it -> second == "AA")
            {
                point += 4;
            }
            if (it -> second == "BA")
            {
                point += 3.5;
            }
            if (it -> second == "BB")
            {
                point += 3;
            }
            if (it -> second == "CB")
            {
                point += 2.5;
            }
            if (it -> second == "CC")
            {
                point += 2;
            }
            if (it -> second == "CD")
            {
                point += 1.5;
            }
            if (it -> second == "DD")
            {
                point += 1;
            }
            if (it -> second == "FF")
            {
                point += 0;
            }
            count++;
        }
        gpa = point / count;
    }
    string printTranscript()
    {
        for( auto it = completedCourses.begin(); it != completedCourses.end(); ++it )
        {
            cout << it->first;
            string& value = it->second;
            cout << " " << value << endl;
        }
    }
public:
    void transcript::getpga()
    {
        return gpa;
    }
    void Transcript::setgpa(double gpa_)
    {
        gpa = gpa_;
    }
