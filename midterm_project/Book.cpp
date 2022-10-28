#include "Book.h"
#include <string>
#include <vector>
#include <fstream>
#include <iostream>
using namespace std;
vector <Book> list_of_books{};
Book::Book() {
	
	ISBN = "";
	ID = "";
	startBorrow = 0;
	expDate = 0;
	Author = "";
	Title = "";
	Category = "";
	Reader = "";
}
Book::Book(string isbn, string title, string author, string category,string id, string reader,long int start,long int exp) {
	ISBN = isbn;
	Title = title;
	Author = author;
	Category = category;
	ID = id;
	Reader = reader;
	startBorrow = start;
	expDate = exp;
}
string Book::getISBN() {
	return ISBN;
}
string Book::getTitle() {
	return Title;
}
string Book::getAuthor() {
	return Author;
}
string Book::getCategory() {
	return Category;
}
string Book::getId() {
	return ID;
}
string Book::getReader() {
	return Reader;
}
void Book::setReader(string reader) {
	Reader = reader;
}
long int Book::getStart() {
	return startBorrow;
}
void Book::setStart(int start) {
	startBorrow = start;
}
long int Book::getexpDate() {
	return expDate;
}
void Book::setexpDate(int ex) {
	expDate = ex;
}
void Book::readData(string const& in) {
	string file = in;
	fstream bookFile(file);
	if (bookFile.fail())
	{
		
		exit(1);
		
	}
	string isbn, id;
	string title, author, category, reader;
	while (!bookFile.eof())
	{
		bookFile >> isbn;
		bookFile >> title;
		bookFile >> author;
		bookFile >> category;
		bookFile >> id;
		Book b = Book(isbn, title, author, category, id, reader, 0, 0);
		list_of_books.push_back(b);
	}
}
void Book::print() {
	for (int i = 0; i < list_of_books.size()-1; i++)
	{
		cout << list_of_books[i].getISBN() << " " << list_of_books[i].getTitle() << " " << list_of_books[i].getAuthor() << " " << list_of_books[i].getCategory() << " " << list_of_books[i].getId()<<endl;
	}
}