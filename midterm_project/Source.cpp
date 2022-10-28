using namespace std;
#include "Book.h"
#include <vector>
#include <iostream>
int main() {
	Book b = Book();
	b.readData("book.txt");
	cout << "hello";
	b.print();
}
