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
	Student(string username, string password, vector <Book> copy_list);
	string getUser();
	void setUser(const string username);
	string getPass();
	void setPass(const string password);
	void printCopies(); 
	bool borrowBook(string isbn);
	bool returnBook(string isbn);
	ostream& operator<< (ostream& output,const Book& book);
	istream operator>> (istream& input, Book* book);
	
	void UI();
	void searchBook();
	void printListOfBooks();
};
