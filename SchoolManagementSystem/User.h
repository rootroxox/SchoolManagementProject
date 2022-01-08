//
// Created by ayber on 7.01.2022.
//

#ifndef XX_USER_H
#define XX_USER_H
#include <string>
using namespace std;

class User {
public:
    string Name, SurName, ID;
public:
    User();
    User(string N, string S, string I);
    User(const User& obj);
    string getName();
    void setName(string N);
    string getSurName();
    void setSurName(string S);
    string getID();
    void setID(string I);
};


#endif //XX_USER_H
