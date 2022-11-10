#include <iostream>
#include "Student.h"
#include "Book.h"
#include <string>
#include <vector>
#include <fstream>
#include <ctime>
#include <cmath>
#include "Teacher.h"
vector <Book> Copy_list;
vector <Student> students;
vector <Teacher> teachers;
vector <clock_t> student_clock;

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
void Student::printCopies(clock_t t) {
	for (int i = 0; i < Copy_list.size(); i++)
	{
		cout << Copy_list[i].getISBN() << " " << Copy_list[i].getTitle() << " " << Copy_list[i].getAuthor() << " " << Copy_list[i].getCategory() << " " << Copy_list[i].getId() << " " << Copy_list[i].getReader() << endl;
		cout << "Time borrowed: " << (float)((t - student_clock[i]) / CLOCKS_PER_SEC) / 5 << " days" << endl;
	}
}
bool Student::borrowBook(string isbn, clock_t t) {
	for (int i = 0; i < list_of_books.size() - 1; i++)
	{
		if (isbn == list_of_books[i].getISBN())
		{
			if (list_of_books[i].getReader() == "")
			{
				Copy_list.push_back(list_of_books[i]);
				list_of_books[i].setReader(username);
				student_clock.push_back(t);
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
		if (students[i].getUser() == u && students[i].getPass() == p)
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
	for (int i = 0; i < students.size(); i++)
	{
		cout << students[i].getUser() << " " << students[i].getPass() << endl;
	}
}
bool Student::returnBook(string isbn) {
	for (int i = 0; i < list_of_books.size() - 1; i++)
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
void sortTwoBooks(vector <Book>& unavailable, int temp_idx, int j) {//temp_idx before j
	//compare titles when only 2
	if (unavailable[temp_idx].getTitle().compare(unavailable[j].getTitle()) == 0) {
		//compare author now
		if (unavailable[temp_idx].getAuthor().compare(unavailable[j].getAuthor()) == 0) {
			//compare isbn now
			if (stoi(unavailable[temp_idx].getISBN()) == stoi(unavailable[j].getISBN())) {
				//compare ID
				if (stoi(unavailable[temp_idx].getId()) > stoi(unavailable[j].getId())) {
					swap(unavailable[temp_idx], unavailable[j]);
				}
			}
			else if (stoi(unavailable[temp_idx].getISBN()) > stoi(unavailable[j].getISBN())) {
				swap(unavailable[temp_idx], unavailable[j]);
			}
		}
		else if (unavailable[temp_idx].getAuthor().compare(unavailable[j].getAuthor()) > 0) {
			swap(unavailable[temp_idx], unavailable[j]);
		}
	}
	else if (unavailable[temp_idx].getTitle().compare(unavailable[j].getTitle()) > 0) {
		swap(unavailable[temp_idx], unavailable[j]);
	}
}
void swap(Book* xp, Book* yp)
{
	Book temp = *xp;
	*xp = *yp;
	*yp = temp;
}
void sortBook(vector <Book> v1) {//make avail and unavail parameters 
	vector <Book> available;
	vector <Book> unavailable;
	for (int i = 0; i < v1.size() - 1; i++) {
		if (v1[i].getReader() != "") {
			available.push_back(v1[i]);
		}
		else {
			unavailable.push_back(v1[i]);
		}
	}
	int j, minimum;//sort exp date in unavailable
	for (int i = 0; i < unavailable.size() - 1; i++) {
		minimum = i;
		for (int j = i + 1; j < unavailable.size(); j++) {
			if (unavailable[j].getexpDate() < unavailable[minimum].getexpDate())
				minimum = j;
			if (minimum != i)
				swap(unavailable[minimum], unavailable[i]);
		}
	}
	int first_idx, last_idx, x;
	for (int j = 0; j < unavailable.size() - 1; j++) {
		if (available[j].getexpDate() == available[j + 1].getexpDate()) {
			first_idx = j;
			x = j + 1;
			while (available[x].getexpDate() == available[x + 1].getexpDate()) {
				x++;
				last_idx = x;
			}
		}
		if ((last_idx - first_idx) == 1)
			sortTwoBooks(unavailable, first_idx, last_idx);
		else {
			for (int i = first_idx; i < last_idx; i++) {
				for (int k = i; k < last_idx - 1; k++) {
					sortTwoBooks(unavailable, k, k + 1);
				}
			}
		}
	}
	for (int i = 0; i < available.size() - 1; i++) {
		for (int j = 0; j < available.size() - 1; j++) {
			sortTwoBooks(available, j, j + 1);
		}
	}
	//print
	for (int i = 0; i < unavailable.size() - 1; i++) {
		cout << unavailable[i].getISBN() << "\t" << unavailable[i].getTitle() << "\t" << unavailable[i].getAuthor() << unavailable[i].getCategory() << endl;
	}
	for (int j = 0; j < unavailable.size() - 1; j++) {
		cout << available[j].getISBN() << "\t" << available[j].getTitle() << "\t" << available[j].getAuthor() << available[j].getCategory() << endl;
	}
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
	string temp, temp1;
	string t, a, j, c;
	switch (cmd) {
	case '1':
	{
		for (int i = 1; i <= list_of_books.size(); i++) {
			for (int j = 1; j <= (list_of_books.size() - i - 1); j++) {
				temp = list_of_books[i].getId();
				temp1 = list_of_books[i].getId();
				if (stoi(temp) > stoi(temp1))
					swap(list_of_books[i], list_of_books[j]);
			}
		}
		cout << "ID: ";
		long int id;
		cin >> id;
		cout << "\n";
		int lo = 0;
		int hi = list_of_books.size() - 1;
		int mid;
		while (hi - lo > 1) {
			int mid = (hi + lo) / 2;
			temp = list_of_books[mid].getId();
			if (stoi(temp) < id) {
				lo = mid + 1;
			}
			else if (stoi(temp) == id) {
				cout << list_of_books[mid].getISBN() << "\t" << list_of_books[mid].getTitle() << "\t" << list_of_books[mid].getAuthor() << "\t" << list_of_books[mid].getCategory() << endl;
			}
			else {
				hi = mid;
			}
		}
		temp1 = list_of_books[lo].getId();
		if (stoi(temp1) == id) {
			cout << list_of_books[lo].getISBN() << "\t" << list_of_books[lo].getTitle() << "\t" << list_of_books[lo].getAuthor() << list_of_books[lo].getCategory() << endl;
		}
		else if (stoi(temp1) == id) {
			cout << list_of_books[lo].getISBN() << "\t" << list_of_books[lo].getTitle() << "\t" << list_of_books[lo].getAuthor() << list_of_books[lo].getCategory() << endl;
		}
		else {
			cout << "Unknown ID. Try Again." << endl;
		}
		break;
	}
	case '2':
		cout << "Title: ";
		cin >> t;
		for (int i = 0; i < list_of_books.size(); i++) {
			if (t.compare(list_of_books[i].getTitle()) == 0)
				cout << list_of_books[i].getISBN() << "\t" << list_of_books[i].getTitle() << "\t" << list_of_books[i].getAuthor() << list_of_books[i].getCategory() << endl; \
			else {
				cout << "No results found by specified key" << endl;
				sortBook(list_of_books);
				break;
			}
		}
		break;
	case '3':
		cout << "Author: ";
		cin >> a;
		for (int i = 0; i < list_of_books.size(); i++) {
			if (a.compare(list_of_books[i].getAuthor()) == 0)
				cout << list_of_books[i].getISBN() << "\t" << list_of_books[i].getTitle() << "\t" << list_of_books[i].getAuthor() << list_of_books[i].getCategory() << endl;
			else {
				cout << "No results found by specified key" << endl;
				sortBook(list_of_books);
				break;
			}
		}
		break;
	case'4':
		cout << "ISBN: ";
		cin >> j;
		for (int i = 0; i < list_of_books.size(); i++) {
			if (j.compare(list_of_books[i].getISBN()) == 0)
				cout << list_of_books[i].getISBN() << "\t" << list_of_books[i].getTitle() << "\t" << list_of_books[i].getAuthor() << list_of_books[i].getCategory() << endl;
			else {
				cout << "No results found by specified key" << endl;
				sortBook(list_of_books);
				break;
			}
		}
		break;
	case'5':
		cout << "Category: ";
		cin >> c;
		for (int i = 0; i < list_of_books.size(); i++) {
			if (c.compare(list_of_books[i].getCategory()) == 0)
				cout << list_of_books[i].getISBN() << "\t" << list_of_books[i].getTitle() << "\t" << list_of_books[i].getAuthor() << list_of_books[i].getCategory() << endl;
			else {
				cout << "No results found by specified key" << endl;
				sortBook(list_of_books);
				break;
			}
		}
		break;
	default:
		cout << "Invalid option. Try Again." << endl;
	}
}


/*other search func / doesnt prioritize
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
	*/
