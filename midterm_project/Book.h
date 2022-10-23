#include <string>
using namespace std;
class Book {
private:
	int ISBN, ID, startBorrow, expDate;
	string Author,Title, Category, Reader;
public:
	Book();
	Book(int isbn, string title, string author, string category, int id, string reader, int start, int exp);
	int getISBN();
	string getTitle();
	string getAuthor();
	string getCategory();
	int getId();
	string getReader();
	void setReader(string reader);
	int getStart();
	void setStart(int start);
	int getexpDate();
	void setexpDate(int ex);

};