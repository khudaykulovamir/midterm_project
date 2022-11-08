//
//  teacher.cpp
//  Midterm_project_teacher_class
//
//  Created by Farhana Rahman on 10/22/22.
#include <iostream>
#include "Student.h"
#include "Book.h"
#include "teacher.h"
#include <fstream>
#include <array>
#include <string>
vector <Book> copy_list_for_teacher;
using namespace std;
Teacher::Teacher() {

    username = "";
    password = "";
    Book copy_list[5];
}

Teacher::Teacher(string name, string password) {

    username = name;
    this->password = password;      //not refering to parameter password and refer to class password

}
void Teacher::printTeachers() {
    for (int i = 0; i < teachers.size() - 1; i++)
    {
        cout << teachers[i].get_username() << " " << teachers[i].get_password() << endl;
    }
}
bool Teacher::checkForTeacher(string u, string p) {
    for (int i = 0; i < teachers.size(); i++)
    {
        if (teachers[i].get_username() == u && teachers[i].get_password() == p)
        {
            return 1;
        }
    }
    return 0;
}
string Teacher::get_username() {

    return username;
}

string Teacher::get_password() {

    return password;
}

int Teacher::get_copies() {

    return max_copies;
}

void Teacher::set_username(string name) {

    username = name;
}

void Teacher::set_password(string password) {

    this->password = password;
}

void Teacher::set_copies(int max_copies) {

    this->max_copies = max_copies;
}
bool Teacher::borrow_book(string isbn) {
	for (int i = 0; i < list_of_books.size() - 1; i++)
	{
		if (isbn == list_of_books[i].getISBN())
		{
			if (list_of_books[i].getReader() == "")
			{
				copy_list_for_teacher.push_back(list_of_books[i]);
				list_of_books[i].setReader(username);

				return 1;
			}
			return 0;
		}
	}

	return 0;

}
void Teacher::searchBook() {
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
	bool found = 0;
	int i;
	switch (cmd) {
	case '1':
		cin >> entry;
		for (i = 0; i < (list_of_books.size() - 1); i++)
		{
			if (entry == list_of_books[i].getId())
			{
				cout << "Book found!" << endl;
				cout << list_of_books[i].getISBN() << " " << list_of_books[i].getTitle() << " " << list_of_books[i].getAuthor() << " " << list_of_books[i].getCategory() << " " << list_of_books[i].getId() << endl;

			}
		}
		break;
	case '2':
		cin >> entry;
		for (i = 0; i < (list_of_books.size() - 1); i++)
		{
			if (entry == list_of_books[i].getTitle())
			{
				cout << "Book found!" << endl;
				cout << list_of_books[i].getISBN() << " " << list_of_books[i].getTitle() << " " << list_of_books[i].getAuthor() << " " << list_of_books[i].getCategory() << " " << list_of_books[i].getId() << endl;

			}
		}
		break;
	case '3':
		cin >> entry;
		for (i = 0; i < (list_of_books.size() - 1); i++)
		{
			if (entry == list_of_books[i].getAuthor())
			{
				cout << "Book found!" << endl;
				cout << list_of_books[i].getISBN() << " " << list_of_books[i].getTitle() << " " << list_of_books[i].getAuthor() << " " << list_of_books[i].getCategory() << " " << list_of_books[i].getId() << endl;

			}
		}
		break;
	case'4':
		cin >> entry;
		for (i = 0; i < (list_of_books.size() - 1); i++)
		{
			if (entry == list_of_books[i].getISBN())
			{
				cout << "Book found!" << endl;
				cout << list_of_books[i].getISBN() << " " << list_of_books[i].getTitle() << " " << list_of_books[i].getAuthor() << " " << list_of_books[i].getCategory() << " " << list_of_books[i].getId() << endl;

			}
		}
		break;
	case'5':
		cin >> entry;
		for (i = 0; i < (list_of_books.size() - 1); i++)
		{
			if (entry == list_of_books[i].getCategory())
			{
				cout << "Book found!" << endl;
				cout << list_of_books[i].getISBN() << " " << list_of_books[i].getTitle() << " " << list_of_books[i].getAuthor() << " " << list_of_books[i].getCategory() << " " << list_of_books[i].getId() << endl;

			}
		}
		break;
	}
}
bool Teacher::return_book(string isbn) {
	for (int i = 0; i < list_of_books.size() - 1; i++)
	{
		if (isbn == list_of_books[i].getISBN()) {
			list_of_books[i].setReader("");
		}
	}
	for (int j = 0; j < copy_list_for_teacher.size(); j++)
	{
		if (isbn == copy_list_for_teacher[j].getISBN()) {
			copy_list_for_teacher.erase(copy_list_for_teacher.begin() + j);
			return 1;
		}
	}
	return 0;
}
void Teacher::printCopies() {
	for (int i = 0; i < copy_list_for_teacher.size(); i++)
	{
		cout << copy_list_for_teacher[i].getISBN() << " " << copy_list_for_teacher[i].getTitle() << " " << copy_list_for_teacher[i].getAuthor() << " " << copy_list_for_teacher[i].getCategory() << " " << copy_list_for_teacher[i].getId() << " " << copy_list_for_teacher[i].getReader() << endl;
	}
}

/*


}





/*bool Teacher::request_book(string isbn, string b_title, string b_author, string b_category) {
	
	//asks user for ISBN
	cout << "Please enter ISBN: " << endl;
	cin >> isbn;
	
	//asks user for book title
	cout << "Please enter book title: " << endl;
	cin >> b_title;
	
	//asks user for book author
	cout << "Please enter book author: " << endl;
	cin >> b_author;
	
	//asks user for book category
	cout << "Please enter category: " << endl;
	cin >> b_category;
	
	//generates a random number for ID
	//There is a way to set a range but idk how at the moment
	int random = rand();
	
	//pushes the object into a list of objects through vectors 
	//Putting the information into the vectors 
	list_of_books.push_back(Book(isbn,b_title,b_author,b_category, random)); 
	return true;
}

bool Teacher::delete_copy(string Id_num){
	
	
	vector<Book>::iterator it = list_of_books.begin();
	
	//goes through the list of books to find the book ID 
	//if the ID is found, continue the rest of the process of deleting
	int j;
	for (j=0; j< list_of_books.size(); j++){
		
		if(Id_num == list_of_books[j].getID()){
			return false;			
		}else{
			continue;
		}
	}
	
	//counter starts where the iterator begins 
	//if the counter equals to j, we found the ID number 
	int counter = 0;
	while(it!= list_of_books.end(){
		
		if (counter == j){
			list_of_books.erase(it);
		}else{
			counter++;
			it++;
		}
	
	}
	
	return true;
			
	}

	
}



//Any book they check out goes into this array
/*void Teacher::input_into_vector(string book) {

    copy_borrow.push_back(book);

}

void Teacher::remove_from_vector(string book) {

    //sends it to the beginning of the vector
    vector<string>::iterator it = copy_borrow.begin();

    while (it != copy_borrow.end()) {

        if ((*it).compare(book) == 0) {
            copy_borrow.erase(it);
        }
        else {
            it++;
        }

    }
}

void Teacher::display() {

    for (string i : copy_borrow) {
        cout << i << endl;
    }

}*/
