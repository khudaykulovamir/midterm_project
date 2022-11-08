//
//  teacher.cpp
//  Midterm_project_teacher_class
//
//  Created by Farhana Rahman on 10/22/22.
//

#include <iostream>
#include "Student.h"
#include "Book.h"
#include <
#include "teacher.h"
#include <fstream>
#include <array>
#include <string>
vector <Book> Copy_list;
vector <Student> students;
vector <Teacher> teachers;
vector <Book> list_of_books{};
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
				Copy_list.push_back(list_of_books[i]);
				list_of_books[i].setReader(username);
                
                return 1;
            }
            return 0;
        }
    }
    
    return 0;   
    
}

bool Teacher::return_book(string isbn) {
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

void Teacher::printCopies() {
	for (int i = 0; i < Copy_list.size(); i++)
	{
		cout << Copy_list[i].getISBN() << " " << Copy_list[i].getTitle() << " " << Copy_list[i].getAuthor() << " " << Copy_list[i].getCategory() << " " << Copy_list[i].getId() << " " << Copy_list[i].getReader() << endl;
	}
}

void UI() {
	char cmd='q';
	cout << "--------------------------------------------------------------------"<< endl;
	cout << "-						Welcome to My Library						-"<< endl;
	cout << "--------------------------------------------------------------------" << endl;
	cout << "\n";
	cout << "Welcome back, Teacher";
	cout << "\n";
	while (cmd != '0') {
		cout << "Please choose:" << endl;
		cout << "\t 1 -- Search Book" << endl;
		cout << "\t 2 -- Borrow Book" << endl;
		cout << "\t 3 -- Return Book" << endl;
		cout << "\t 4 -- Renew Book" << endl;
        cout << "\t 5 -- Request a new book copy << endl;
        cout << "\t 6 -- Delete an existing copy << endl;
		/*add more options here*/
		cout << "\t 0 -- Log Out" << endl;
		cin >> cmd;
		switch (cmd) {
		case '1':
			/*search book func*/
			break;
		case '2':
			borrow_book();
			break;
		case '3':
			returnBook();
			break;
		case '4':
			/*renew book*/
			break;
        case '5':   
            /*Request book*/  
		request_book(); 	
            break;
        case '6':  
		
		 /*Delete book*/ 
		string Id_num;
		cout << "Enter ID number: " << endl;
		cin >> Id_num;	
				
		if (delete_copy(Id_num) == false){
			cout << "Book not found!" << endl;
			exit(1);
		}
				   
            break;
		default:
			cout << "Invalid Command. Try Again!" << endl;
			continue;
		}
	}
	cout << "Logging Out..." << endl;
	exit(1);
}

bool Teacher::request_book(string isbn, string b_title, string b_author, string b_category){
	
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
