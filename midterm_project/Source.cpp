
#include "Book.h"
#include "Student.h"
#include "Teacher.h"
#include <vector>
#include <iostream>
#include <string>
#include <ctime>
using namespace std;
int main() {
	Book B = Book();
	B.readData("book.txt");
	B.clear();
	B.readData("book.txt");
	clock_t time_req;
	bool successLogin=0;
	time_req = clock();
	string username, password; 
	Student s = Student();
	s.readFile("student.txt");
	Teacher t = Teacher();
	time_req = clock();
	/*cout << "Enter username: ";
	cin >> username;
	cout << "Enter password: ";
	cin >> password;
	time_req = clock() - time_req;
	cout << (float)time_req / CLOCKS_PER_SEC;*/
	
	while (successLogin==0)
	{
		cout << "Enter username: ";
		cin >> username;
		cout << "Enter password: ";
		cin >> password;
		if (s.checkForStudent(username, password)==1)
		{
			cout << "Welcome Student!"<<endl;
			successLogin = 1;
			char cmd = 'q';
			Student s1 = Student(username, password);
			while (cmd!='0')
			{
				
				cout << endl;
				cout << "--------------------------------------------------------------------" << endl;
				cout << "-						Welcome to My Library						-" << endl;
				cout << "--------------------------------------------------------------------" << endl;
				cout << "\n";
				cout << "Welcome back, Student";
				cout << "\n";
					cout << "Please choose:" << endl;
					cout << "\t 1 -- Search Book" << endl;
					cout << "\t 2 -- Borrow Book" << endl;
					cout << "\t 3 -- Return Book" << endl;
					cout << "\t 4 -- Renew Book" << endl;
					cout << "\t 5 -- Print My List Of Books" << endl;
					/*add more options here*/
					cout << "\t 0 -- Log Out" << endl;
					cin >> cmd;
					string isbn;
					bool b;
					switch (cmd) {
					case '1':
						s1.searchBook();
						break;
					case '2':
						
						cout << endl << "Enter isbn of book: ";
						cin >> isbn;
						 b=s1.borrowBook(isbn, clock());
						if (b)
						{
							cout << "Succesfully borrowed book!";
						}
						else {
							cout << "Failed to borrow!";
						}
						break;
					case '3':
						cout << endl << "Enter isbn of book: ";
						cin >> isbn;
						b =s1.returnBook(isbn);
						if (b)
						{
							cout << "Succesfully returned book!";
						}
						else {
							cout << "Failed to return!";
						}
						break;
					case '4':
						/*renew book*/
						break;
					case '5':
						s1.printCopies(clock());
						break;
					
					}
				
				
				
			}
			successLogin = 0;
			cout << endl << "Logged out!" << endl;
		}
		if (t.checkForTeacher(username, password) == 1)
		{
			cout << "Welcome Teacher!"<<endl;
			successLogin = 1;
			char cmd = 'q';
			Teacher t1 = Teacher(username, password);
			while (cmd != '0')
			{
				string id;
				cout << endl;
				cout << "--------------------------------------------------------------------" << endl;
				cout << "-						Welcome to My Library						-" << endl;
				cout << "--------------------------------------------------------------------" << endl;
				cout << "\n";
				cout << "Welcome back, Teacher";
				cout << "\n";
				cout << "Please choose:" << endl;
				cout << "\t 1 -- Search Book" << endl;
				cout << "\t 2 -- Borrow Book" << endl;
				cout << "\t 3 -- Return Book" << endl;
				cout << "\t 4 -- Renew Book" << endl;
				cout << "\t 5 -- Print My List Of Books" << endl;
				cout << "\t 6 -- Request Copy" << endl;
				cout << "\t 7 -- Delete Copy" << endl;
				/*add more options here*/
				cout << "\t 0 -- Log Out" << endl;
				cin >> cmd;
				string isbn;
				bool b;
				switch (cmd) {
				case '1':
					t1.searchBook();
					break;
				case '2':

					cout << endl << "Enter isbn of book: ";
					cin >> isbn;
					b = t1.borrow_book(isbn);
					if (b)
					{
						cout << "Succesfully borrowed book!";
					}
					else {
						cout << "Failed to borrow!";
					}
					break;
				case '3':
					cout << endl << "Enter isbn of book: ";
					cin >> isbn;
					b = t1.return_book(isbn);
					if (b)
					{
						cout << "Succesfully returned book!";
					}
					else {
						cout << "Failed to return!";
					}
					break;
				case '4':
					/*renew book*/
					break;
				case '5':
					t1.printCopies();
					break;
				case'6':
					t1.request_book();
					B.print();
					break;
				case '7':
					cout << "Enter ID: ";
					cin >> id;
					b = t1.delete_copy(id);
					if (b)
					{
						cout << "succesfully deleted copy"<<endl;
					}
					else {
						cout << "Failed to delete";
					}

				}



			}
			successLogin = 0;
			cout << endl << "Logged out!" << endl;
		}
		
		
	}
}
