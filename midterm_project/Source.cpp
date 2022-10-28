using namespace std;
#include "Book.h"
#include "Student.h"
#include <vector>
#include <iostream>
int main() {
	Book b = Book();
	vector<Book> s1;
	b.clear();
	Student s = Student("Amir", "123", s1);
	b.readData("book.txt");
	
	cout << s.borrowBook("9780486661032");

	cout << endl;
	//b.print();
	s.returnBook("9780486661032");
	s.printListOfBooks();
	cout << endl;
	b.print();
}
