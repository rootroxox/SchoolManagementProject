#include "User.h"
#include "iostream"
User::User() {
    Name = "";
    SurName = "";
    ID = "";
}

User::User(string N, string S, string I) {
    Name = N;
    SurName = S;
    ID = I;
}

string User::getName() {
    return Name;
}

void User::setName(string N) {
    Name = N;
}

string User::getSurName() {
    return SurName;
}

void User::setSurName(string S) {
    SurName = S;
}

string User::getID() {
    return ID;
}

void User::setID(string I) {
    ID = I;
}

ostream &operator << (ostream &os, const User U){
    os << endl << "Name: " << U.Name << " Surname: " << U.SurName << " ID: " << U.ID << endl;
}