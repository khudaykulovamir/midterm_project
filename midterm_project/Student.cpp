#include <iostream>
#include "Student.h"
#include "Book.h"
#include <string>
#include <vector>
vector <Book> Copy_list;
Student::Student() {
	username = "";
	password = "";
	
	//Book arr[5];
}
Student::Student(string username, string password, vector <Book> copy_list) {
	this->username = username;
	this->password = password;
	Copy_list = copy_list;
	num_of_books = 0;
}
void Student::printListOfBooks() {
	for (int i = 0; i < Copy_list.size(); i++)
	{
		cout << Copy_list[i].getISBN() << " " << Copy_list[i].getTitle() << " " << Copy_list[i].getAuthor() << " " << Copy_list[i].getCategory() << " " << Copy_list[i].getId() << " " << Copy_list[i].getReader() << endl;
	}
}
bool Student::borrowBook(string isbn) {
	
	for (int i = 0; i < list_of_books.size() - 1; i++)
	{
		if (isbn == list_of_books[i].getISBN())
		{
			if (list_of_books[i].getReader()=="")
			{
				Copy_list.push_back(list_of_books[i]);
				list_of_books[i].setReader(username);
				
				return 1;
			}
			return 0;
		}
	}

	return 0;

}bool Student::returnBook(string isbn) {
	for (int i = 0; i < list_of_books.size() - 1; i++)
	{
		if (isbn == list_of_books[i].getISBN()) {
			list_of_books[i].setReader("");
		}
	}
	for (int j = 0; j < Copy_list.size(); j++)
	{
		if (isbn == Copy_list[j].getISBN()) {
			Copy_list.erase(Copy_list.begin()+j);
			return 1;
		}
	}
	return 0;

}
string Student::getUser() {
	return username;
}
void Student::setUser(const string username) {
	this->username = username;
}
string Student::getPass() {
	return password;
}
void Student::setPass(const string password) {
	this->password = password;
}
/*void Student::printCopies() {
	for (int i = 0; i < 5; i++) {
		cout << copy_list[0].print() << endl; //some book print member function
	}
}
void Student::insertCopy(const Book b1) {
	//int i = 0;
	//Book temp = b1;
	Book temp(b1.getISBN(), b1.getTitle(), b1.getAuthor(), b1.getCategory(), b1.getId(), b1.getReader(), b1.getStart(), b1.getexpDate()); //unless there is some book copy function
	if (i++ > 5) {
		cout << "The maximum number of copies a student can have is 5!" << endl;
		return;
	}
	else {
		//arr[i] = b1;
	//	i++;

		copy_list.pop_back();
		copy_list.insert(copy_list.begin(), temp);
	}
	//for (int i = 0; i < 5; i++)
	//{
		//if (arr[i].getISBN == "4561854") {
			//arr[i] = NULL;
		//}
	//}
}
void Student::deleteCopy(Book b1) {
	for (int i = 0; i < 5; i++) {
		if (b1.getId() == copy_list[i].getId()) {//id must be unique to work
			Book empty;
			empty.swap(copy_list[i]);
		}
		else {
			cout << "Copy \"" << empty.getTitle() << "\" wasn't borrowed!" << endl;
		}
	}
}*/