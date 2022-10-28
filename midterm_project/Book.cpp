#include "Book.h"
#include <string>
#include <vector>
#include <fstream>
#include <iostream>
using namespace std;
vector <Book> list_of_books{};
Book::Book() {
	
	ISBN = 0;
	ID = 0;
	startBorrow = 0;
	expDate = 0;
	Author = "";
	Title = "";
	Category = "";
	Reader = "";
}
Book::Book(int isbn, string title, string author, string category, int id, string reader, int start, int exp) {
	ISBN = isbn;
	Title = title;
	Author = author;
	Category = category;
	ID = id;
	Reader = reader;
	startBorrow = start;
	expDate = exp;
}
int Book::getISBN() {
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
int Book::getId() {
	return ID;
}
string Book::getReader() {
	return Reader;
}
void Book::setReader(string reader) {
	Reader = reader;
}
int Book::getStart() {
	return startBorrow;
}
void Book::setStart(int start) {
	startBorrow = start;
}
int Book::getexpDate() {
	return expDate;
}
void Book::setexpDate(int ex) {
	expDate = ex;
}
void Book::readData(string const& in) {
	fstream bookFile(in);
	if (bookFile.fail())
	{
		exit(1);
		
	}
	int isbn, id;
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
	for (int i = 0; i < list_of_books.size(); i++)
	{
		cout << list_of_books[i].getISBN() << " " << list_of_books[i].getTitle() << " " << list_of_books[i].getAuthor() << " " << list_of_books[i].getCategory() << " " << list_of_books[i].getId();
	}
}