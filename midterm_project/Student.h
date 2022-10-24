#pragma once
#include <string>
#include "Book.h"
#include <vector>
using namespace std;
class Student {
private:
	string username, password;
	int max_copies;
	vector <Book> copy_list;
public:
	Student();
	Student(string username, string password, vector <Book> copy_list);
	string getUser();
	void setUser(const string username);
	string getPass();
	void setPass(const string password);
	void printCopies();
	void insertCopy(const Book b1);
	void deleteCopy(const Book b1);
};