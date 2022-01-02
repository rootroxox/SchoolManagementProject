#ifndef USER_USER_H
#define USER_USER_H
#include <string>
using namespace std;

class User {
private:
    string Name, SurName, ID;
public:
    User();
    User(string N, string S, string I);
    string getName();
    void setName(string N);
    string getSurName();
    void setSurName(string S);
    string getID();
    void setID(string I);
    friend ostream &operator << (ostream &os, const User U);
};


#endif //USER_USER_H
