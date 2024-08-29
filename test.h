//
// Created by 15496 on 2024/8/10.
//
//登录功能
#include <iostream>
#include <vector>
#include <string>
using namespace std;

class User {
public:
    string username;
    string password;
    User(string u, string p) : username(u), password(p) {}
    bool login(const string &username, const string &password) {
        return this->username == username && this->password == password;
    }
    void printInfo() {
        cout << "Username: " << username << ", Password: " << password << endl;
    }

};
