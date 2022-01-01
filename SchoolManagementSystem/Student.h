#ifndef STUDENT_H
#define STUDENT_H

#include <string>
#include <Instructor.h>
#include <Transcript.h>
#include <Curriculum.h>
#include <vector>

class Student : public User{
protected:
	double GPA;
	int classLevel;
	std::string faculty;
	std::string department;
	Instructor advisor;
	int rank;
	Transcript transcript;
	Curriculum curriculum;
	vector<Course> takenCourses;

public:

	Student(std::string name, std::string surname, std::string ID, int classLevel, std::string faculty, std::string department, int rank);

	void setGPA(double);

	double getGPA();

	void setClassLevel(int);

	int getClassLevel();

	void setFaculty(std::string);

	std::string getFaculty();

	void setDepartment(std::string);

	std::string getDepartment();

	void setAdvisor(Instructor);

	Instructor getAdvisor();

	void setRank(int);

	int getRank();

	void setTranscript(Transcript);

	Transcript getTranscript();

	void setCurriculum(Curriculum);

	Curriculum getCurriculum();

	void setTakenCourses(vector<Course>);

	vector<Course> getTakenCourses();

	void printTranscript();

	void printCurriculum();

	void printTakenCourses();

	bool enrollCourse(Course);

	bool ejectCourse(Course);
};

#endif // !STUDENT_H
