#include <string>
#include <vector>
using namespace std;
#pragma once

class Book {
private:
	string ISBN, ID;
	long int startBorrow, expDate;
	string Author,Title, Category, Reader;
public:
	
	Book();
	Book( string isbn, string title, string author, string category, string id, string reader, long int start,long int exp);
	string getISBN();
	string getTitle();
	string getAuthor();
	string getCategory();
	string getId();
	string getReader();
	void setReader(string reader);
	long int getStart();
	void setStart(int start);
	long int getexpDate();
	void setexpDate(int ex);
	void readData(string const& in);
	void print();
	void clear();
};
extern vector <Book> list_of_books;