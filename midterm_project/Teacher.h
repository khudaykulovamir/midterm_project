#ifndef teacher_hpp
#define teacher_hpp

#include <stdio.h>
#include <iostream>
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
    Teacher(string name, string password, int max_copies);
    string get_username();
    string get_password();
    int get_copies();


    void display_array();
    void input_into_array(string book);
    void set_username(string name);
    void set_password(string password);
    void set_copies(int max_copies);
    void remove_into_array(string book); //deleting a book






};