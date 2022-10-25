//
//  teacher.cpp
//  Midterm_project_teacher_class
//
//  Created by Farhana Rahman on 10/22/22.
//

#include "teacher.hpp"
#include <array>

Teacher::Teacher() {

    username = "Dr.Giambrone";
    password = "stonybrook2024";
    max_copies = 0;
}

Teacher::Teacher(string name, string password, int max_copies) {

    username = name;
    this->password = password;      //not refering to parameter password and refer to class password
    this->max_copies = max_copies;
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


void Teacher::display_array() {
    for (string i : copy_borrow) {
        cout << i << endl;
    }

}

//Any book they check out goes into this array
void Teacher::input_into_array(string book) {

    copy_borrow[array_length] = book;
    array_length++;

}