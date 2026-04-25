#include "User.h"

User::User(string u, string p) {
    username = u;
    password = p;
}

string User::getUsername() {
    return username;
}

string User::getPassword() {
    return password;
}