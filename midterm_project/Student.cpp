#include <iostream>
#include "Student.h"
#include "Book.h"
#include <string>
#include <vector>
#include <fstream>
#include "Teacher.h"
vector <Book> Copy_list;
vector <Student> students;
vector <Teacher> teachers;
using namespace std;
Student::Student() {
	username = "";
	password = "";
	Book copy_list[5];
}

Student::Student(string username, string password) {
	this->username = username;
	this->password = password;
	
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
	for (int i = 0; i < Copy_list.size(); i++)
	{
		cout << Copy_list[i].getISBN() << " " << Copy_list[i].getTitle() << " " << Copy_list[i].getAuthor() << " " << Copy_list[i].getCategory() << " " << Copy_list[i].getId() << " " << Copy_list[i].getReader() << endl;
	}
}
bool Student::borrowBook(string isbn) {
	for (int i = 0; i < list_of_books.size(); i++)
	{
		if (isbn == list_of_books[i].getISBN())
		{
			if (list_of_books[i].getReader() == "")
			{
				Copy_list.push_back(list_of_books[i]);
				list_of_books[i].setReader(username);
				
				return 1;
			}
			return 0;
		}
	}

	return 0;

}
bool Student::checkForStudent(string u, string p) {
	for (int i = 0; i < students.size(); i++)
	{
		if (students[i].getUser()==u&&students[i].getPass()==p)
		{
			return 1;
		}
	}
	return 0;
}
bool Student::readFile(string in) {
	string file = in;
	fstream bookFile(file);
	if (bookFile.fail())
	{

		exit(1);

	}
	int i;
	string username, password;
	
	while (!bookFile.eof())
	{
		bookFile >> i;
		bookFile >> username;
		bookFile >> password;
		//cout << i <<" "<< username << " " << password<<endl;
		if (i == 0)
		{
			Student s = Student(username, password);
			students.push_back(s);
		}
		else
		{
			Teacher t = Teacher(username, password);
			teachers.push_back(t);
		}
		
	}
}
void Student::printStudents() {
	for (int i = 0; i < students.size() ; i++)
	{
		cout << students[i].getUser() << " " << students[i].getPass()<<endl;
	}
}
bool Student::returnBook(string isbn) {
	for (int i = 0; i < list_of_books.size() ; i++)
	{
		if (isbn == list_of_books[i].getISBN()) {
			list_of_books[i].setReader("");
		}
	}
	for (int j = 0; j < Copy_list.size(); j++)
	{
		if (isbn == Copy_list[j].getISBN()) {
			Copy_list.erase(Copy_list.begin() + j);
			return 1;
		}
	}
	return 0;
}

/*ostream& Student::operator<< (ostream& output, Book* book) {
	string studentname = "NONE";
	if (!book)
		return output;
	if (book->getReader() == "")
		studentname = book->getReader();
	output << "\tID : \ t \ t" << book->getId() << endl;
	output << "\tTitle : \ t \ t" << book->getTitle() << endl;
	output << "\tAuthor : \ t \ t" << book->getAuthor() << endl;
	output << "\tCategory : \ t \ t" << book->getCategory() << endl;
	output << "\tID : \ t \ t" << book->getId() << endl;//get # of copies

	
}
istream& Student::operator>> (istream& input, Book* book) {
	string id;
	int borrow, expire;
	string isbn, studentname;
	bool available;
	input >> id >> isbn >> studentname >> available >> borrow >> expire;//double check
}*/
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
void Student::searchBook() {
	char cmd = 'q';
	cout << "\n \n";
	cout << "Search Book By:" << "\n" << "\n";
	cout << "\t 1 -- ID" << endl;
	cout << "\t 2 -- Title" << endl;
	cout << "\t 3 -- Author" << endl;
	cout << "\t 4 -- ISBN" << endl;
	cout << "\t 5 -- Category" << endl;
	cin >> cmd;
	string entry;
	bool found=0;
	int i;
	switch (cmd) {
		case '1':
			cin >> entry;
			for ( i = 0; i < (list_of_books.size()); i++)
			{
				if (entry == list_of_books[i].getId())
				{
					cout << "Book found!"<<endl;
					cout << list_of_books[i].getISBN() << " " << list_of_books[i].getTitle() << " " << list_of_books[i].getAuthor() << " " << list_of_books[i].getCategory() << " " << list_of_books[i].getId()  << endl;

				}
			}
			break;
		case '2':
			cin >> entry;
			for (i = 0; i < (list_of_books.size() ); i++)
			{
				if (entry == list_of_books[i].getTitle())
				{
					cout << "Book found!"<<endl;
					cout << list_of_books[i].getISBN() << " " << list_of_books[i].getTitle() << " " << list_of_books[i].getAuthor() << " " << list_of_books[i].getCategory() << " " << list_of_books[i].getId() << endl;

				}
			}
			break;
		case '3':
			cin >> entry;
			for (i = 0; i < (list_of_books.size() ); i++)
			{
				if (entry == list_of_books[i].getAuthor())
				{
					cout << "Book found!"<<endl;
					cout << list_of_books[i].getISBN() << " " << list_of_books[i].getTitle() << " " << list_of_books[i].getAuthor() << " " << list_of_books[i].getCategory() << " " << list_of_books[i].getId() << endl;

				}
			}
			break;
		case'4':
			cin >> entry;
			for (i = 0; i < (list_of_books.size() ); i++)
			{
				if (entry == list_of_books[i].getISBN())
				{
					cout << "Book found!"<<endl;
					cout << list_of_books[i].getISBN() << " " << list_of_books[i].getTitle() << " " << list_of_books[i].getAuthor() << " " << list_of_books[i].getCategory() << " " << list_of_books[i].getId() << endl;

				}
			}
			break;
		case'5':
			cin >> entry;
			for (i = 0; i < (list_of_books.size() ); i++)
			{
				if (entry == list_of_books[i].getCategory())
				{
					cout << "Book found!"<<endl;
					cout << list_of_books[i].getISBN() << " " << list_of_books[i].getTitle() << " " << list_of_books[i].getAuthor() << " " << list_of_books[i].getCategory() << " " << list_of_books[i].getId() << endl;

				}
			}
			break;
	}
}

