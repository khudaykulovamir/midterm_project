
/*#include <iostream>
#include "teacher.h"

using namespace std;

int main() {

    //maximum borrowing periods ??
    string u_name;  //username
    string p_word;  //password
    int max_cop;    //max copies
    string copy_borrow[10];     //list of copies borrowed

    //creates the object
    Teacher t1;


    //This is for T2
    cout << "Enter a username: ";
    cin >> u_name;

    cout << "Enter your password: ";
    cin >> p_word;

    cout << "How many books are you checking out: ";
    cin >> max_cop;

    if (max_cop > 10) {
        cout << "Cannot check out more than 10!!" << endl;
        cout << "Re-enter number of books checking out: ";
        cin >> max_cop;
    }

    //

    Teacher t2(u_name, p_word, max_cop);

    t2.input_into_array("Goodnight Moon");
    t2.input_into_array("Good afternoon Moon");
    t2.input_into_array("Go to sleep Moon");
    t2.input_into_array("Goodmoning Moon");

    t2.display_array();

    t2.remove_into_array("Good afternoon Moon");

    t2.display_array();


}*/