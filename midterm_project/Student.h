#pragma once
#include <string>
#include "Book.h"
#include <vector>
#include <ctime>
#include <cmath>
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
	void printCopies(clock_t t);
	bool borrowBook(string isbn, clock_t t);
	bool returnBook(string isbn);
//	ostream& operator<< (ostream& output,const Book& book);
	//istream operator>> (istream& input, Book* book);
	bool readFile(string fileName);
	void UI();
	void searchBook();
	void sortBook(vector <Book> v1);
	void printStudents();
	void printListOfBooks();
	bool checkForStudent(string u, string p);
	void swap(Book *xp, Book *yp);
};
extern vector <Student> students;
extern vector <clock_t> student_clock;
