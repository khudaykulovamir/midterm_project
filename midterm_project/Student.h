#pragma once
#include <string>
#include "Book.h"
#include <vector>

using namespace std;
class Student {
private:
	string username, password;
public:
	Student();
	Student(string username, string password);
	string getUser();
	void setUser(const string username);
	string getPass();
	void setPass(const string password);
	void printCopies(); 
	bool borrowBook(string isbn);
	bool returnBook(string isbn);
//	ostream& operator<< (ostream& output,const Book& book);
	//istream operator>> (istream& input, Book* book);
	bool readFile(string fileName);
	void UI();
	void searchBook();
	void printStudents();
	void printListOfBooks();
	bool checkForStudent(string u, string p);
};
extern vector <Student> students;