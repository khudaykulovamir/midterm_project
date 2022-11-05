using namespace std;
#include "Book.h"
#include "Student.h"
#include <vector>
#include <iostream>
#include <string>
#include <ctime>
#include "Teacher.h"
int main() {
	clock_t time_req;
	bool successLogin=0;
	time_req = clock();
	string username, password; 
	Student s = Student();
	s.readFile("student.txt");
	Teacher t = Teacher();
	/*time_req = clock();
	cout << "Enter username: ";
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
		}
		if (t.checkForTeacher(username, password) == 1)
		{
			cout << "Welcome Teacher!"<<endl;
			successLogin = 1;
		}
		if (successLogin==0)
		{
			cout << "Login or Password is incorrect!" << endl;
		}
		
	}
}
