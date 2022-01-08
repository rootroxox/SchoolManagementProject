//
// Created by ayber on 7.01.2022.
//

#include "User.h"

User::User(const User& obj) {
    Name = obj.Name;
    ID = obj.ID;
    SurName = obj.SurName;
}

User::User() {
    Name = "XX";
    SurName = "XX";
    ID = "XX";
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