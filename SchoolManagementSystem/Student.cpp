#include <iostream>
#include "Student.h"
#include <unordered_map>

Student::Student(std::string name, std::string surname, std::string ID, int classLevel, std::string faculty, std::string department, int rank) {
	this->name = name;
	this->surname = surname;
	this->ID = ID;
	this->classLevel = classLevel;
	this->faculty = faculty;
	this->department = department;
	this->rank = rank;
}

void Student::setGPA(double GPA) {
	this->GPA = GPA;
}

double Student::getGPA() {
	return this->GPA;
}

void Student::setClassLevel(int classLevel) {
	this->classLevel = classLevel;
}

int Student::getClassLevel() {
	return this->classLevel;
}

void Student::setFaculty(std::string faculty) {
	this->faculty = faculty;
}

std::string Student::getFaculty() {
	return this->faculty;
}

void Student::setDepartment(std::string department) {
	this->department = department;
}

std::string Student::getDepartment() {
	return this->department;
}

void Student::setAdvisor(Instructor advisor) {
	this->advisor = advisor;
}

Instructor Student::getAdvisor() {
	return this->advisor;
}

void Student::setRank(int rank) {
	this->rank = rank;
}

int Student::getRank() {
	return this->rank;
}

void Student::setTranscript(Transcript transcript) {
	this->transcript = transcript;
}

Transcript Student::getTranscript() {
	return this->transcript;
}

void Student::setCurriculum(Curriculum curriculum) {
	this->curriculum = curriculum;
}

Curriculum Student::getCurriculum() {
	return this->curriculum;
}

void Student::setTakenCourses(vector<Course> takenCourses) {
	this->takenCourses = takenCourses;
}

vector<Course> Student::getTakenCourses() {
	return this->takenCourses;
}

void Student::printTranscript() {
	for (auto const& pair : this->getTranscript()->completedCourses) {
		std::cout << "Course: " << pair.first->courseCode << " " << "Grade: " << pair.second << std::endl;
	}
}

void Student::printCurriculum() {
	std::cout << "Department: " << this->department << "\n" << std::endl;

	for (auto const& pair : this->getCurriculum()->courseList) {
		std::cout << "Course: " << pair.first->courseCode << " " << "Semester: " << pair.second << std::endl;
	}
}

void Student::printTakenCourses() {
	for (int i = 0; i < this->getTakenCourses().size(); i++) {
		std::cout << "Course Code: " << this->getTakenCourses()[i].courseCode
			<< "\nCourse Name: " << this->getTakenCourses()[i].courseName
			<< "\nCredit: " << this->getTakenCourses()[i].credit
			<< std::endl;

		std::cout << std::endl;
	}
}


bool Student::enrollCourse(Course course) {
	this->getTakenCourses().push_back(course);

	if (std::find(this->getTakenCourses().begin(), this->getTakenCourses().end(), course) != this->getTakenCourses().end()) {
		return true;
	}
	return false;
}

bool Student::ejectCourse(Course course) {
	this->getTakenCourses().erase(std::remove(this->getTakenCourses().begin(), this->getTakenCourses().end(), course), this->getTakenCourses().end());

	if (std::find(this->getTakenCourses().begin(), this->getTakenCourses().end(), course) != this->getTakenCourses().end()) {
		return false;
	}
	return true;
}

