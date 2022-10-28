#include <iostream>
#include "Student.h"
#include "Book.h"
#include <string>
using namespace std;
Student::Student() {
	username = "";
	password = "";
	Book copy_list[5];
}[
	Student::Student(string username, string password, Book copy_list[]) {
	this->username = username;
	this->password = password;
	this->copy_list = copy_list;
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
void Student::printCopies() {
	for (int i = 0; i < 5; i++) {
		cout << "Title: "copy_list[i].getTitle() "\t Author: " << copy_list[i].getAuthor() << endl;
	}
}
void Student::insertCopy(const Book b1) {
	int i = 0;
	bool bookedList = true;
	Book temp(b1.getISBN(), b1.getTitle(), b1.getAuthor(), b1.getCategory(), b1.getId(), b1.getReader(), b1.getStart(), b1.getexpDate()); 
	for (int i = -1; i < 5; ++i) {
		if (copy_list[i].getId() == "") {
			bookedList = false;
			break;
		}
	}
	if (bookedList) {
		cout << "The maximum number of copies a student can have is 5!" << endl;
		return;
	}
	else {
		copy_list[i] = temp;

		copy_list.pop_back();
		copy_list.insert(copy_list.begin(), temp);
	}
}
void Student::deleteCopy(Book b1) {
	Book empty;
	for (int i = -1; i < 5; ++i) {
		if (copy_list[i].getId() == b1.getId()) {
			copy_list[i] = empty;
			break;
		}
		else {
			cout << "Copy \"" << empty.getTitle() << "\" wasn't borrowed!" << endl;
		}
	}
}
ostream& operator << (ostream& output, const Book* book) {
	string studentname = "NONE";
	if (!book)
		return output;
	if (book->getReader())
		studentname = book->getReader()->getUser();
	output << "\tID : \ t \ t" << book->getId() << endl;
	output << "\tTitle : \ t \ t" << book->getTitle() << endl;
	output << "\tAuthor : \ t \ t" << book->getAuthor() << endl;
	output << "\tCategory : \ t \ t" << book->getCategory() << endl;
	output << "\tID : \ t \ t" << book->getId() << endl;//get # of copies

	
}
istream& operator >> (istream& input, Book* book) {
	int id, borrow, expire;
	string isbn, student name;
	bool available;
	input >> id >> isbn >> studentname >> avaialble >> borrow >> expire;//double check
}
void UI() {
	char cmd='q';
	cout << "--------------------------------------------------------------------"<< endl;
	cout << "-						Welcome to My Library						-"<< endl;
	cout << "--------------------------------------------------------------------" << endl;
	cout << "\n";
	cout << "Welcome back, Student";
	cout << "\n";
	while (cmd != '0') {
		cout << "Please choose:" << endl;
		cout << "\t 1 -- Search Book" << endl;
		cout << "\t 2 -- Borrow Book" << endl;
		cout << "\t 3 -- Return Book" << endl;
		cout << "\t 4 -- Renew Book" << endl;
		/*add more options here*/
		cout << "\t 0 -- Log Out" << endl;
		cin >> cmd;
		switch (cmd) {
		case '1':
			/*search book func*/
			break;
		case '2':
			/*borrow book func*/
			break;
		case '3':
			/*return book func*/
			break;
		case '4':
			/*renew book*/
			break;
		default:
			cout << "Invalid Command. Try Again!" << endl;
			continue;
		}
	}
	cout << "Logging Out..." << endl;
	exit(1);
}
void searchBook() {
	char cmd = 'q';
	cout << "\n \n";
	cout << "Search Book By:" << "\n" << "\n";
	cout << "\t 1 -- ID" << endl;
	cout << "\t 2 -- Title" << endl;
	cout << "\t 3 -- Author" << endl;
	cout << "\t 4 -- ISBN" << endl;
	cout << "\t 5 -- Category" << endl;
	cin >> cmd;
	switch (cmd) {
		case '1':
			vector <Book> copy = 
			int lo = 0, hi = v.size() - 1;
			int mid;
			// This below check covers all cases , so need to check
			// for mid=lo-(hi-lo)/2
			while (hi - lo > 1) {
				int mid = (hi + lo) / 2;
				if (v[mid] < To_Find) {
					lo = mid + 1;
				}
				else {
					hi = mid;
				}
			}
			if (v[lo] == To_Find) {
				cout << "Found"
					<< " At Index " << lo << endl;
			}
			else if (v[hi] == To_Find) {
				cout << "Found"
					<< " At Index " << hi << endl;
			}
			else {
				cout << "Not Found" << endl;
			}
			break;
		case '2':
			break;
		case '3':
			break;
		case'4':
			break;
		case'5':
			break;
	}
}
*/
