#ifndef teacher_hpp
#define teacher_hpp

#include <stdio.h>
#include <iostream>
#include <vector>
using namespace std;
#endif /* teacher_hpp */

class Teacher {

private:
    string username;
    string password;
    int max_copies;
    string copy_borrow[10];
    int array_length = 0;


public:
    Teacher();
    Teacher(string name, string password);
    string get_username();
    string get_password();
    int get_copies();
    void printTeachers();
    bool checkForTeacher(string u, string p);
    void display_array();
    void input_into_array(string book);
    void set_username(string name);
    void set_password(string password);
    void set_copies(int max_copies);
    bool borrow_book(string isbn);
    bool return_book(string isbn);
    void UI();
   // void searchBook;
    bool request_book();
    bool delete_copy(string ID_num);
    void printCopies();

    void searchBook();




};
extern vector <Teacher> teachers;
extern vector <Book> copy_list_for_teacher;
