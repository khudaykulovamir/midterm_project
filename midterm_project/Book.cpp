#include "Book.h";
#include <string>;
using namespace std;
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