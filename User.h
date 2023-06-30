#pragma once
#include<iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;
class User 
{
	string _name;
	string _login;
	string _pass;

public:
	User(string name, string login, string pass) :_name(name), _login(login), _pass(pass) {}

	friend fstream& operator >>(fstream& is, User& obj);
	friend ostream& operator <<(ostream& os, const User& obj);
	string get_name() { return _name; }
	string get_login() { return _login; }
	string get_password() { return _pass; }
};

class Users_data
{
public:
	Users_data()
	{
		count = 0;
	}

	inline int count_User() { return count; }

	void add_User(User new_User)
	{
		count++;
		data.push_back(new_User);
	}

	User& operator[](int i) { return data[i]; }

protected:
	int count; // counter of Users
	vector<User> data;

};