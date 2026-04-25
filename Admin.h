#ifndef ADMIN_H
#define ADMIN_H
#include "User.h"
using namespace std;

class Admin : public User {
public:
    Admin(string, string);
	void menu();
};

#endif