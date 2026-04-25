#ifndef USER_H
#define USER_H

#include <string>
using namespace std;

class User {
protected:
    string username;
    string password;

public:
    User(string u, string p);
    string getUsername();
    string getPassword();
    virtual void menu() = 0;
    virtual ~User() {}
};

#endif