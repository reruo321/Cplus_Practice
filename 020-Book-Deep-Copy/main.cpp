#include "Book.h"

using namespace std;

int main() {

	cout << endl << "-----Book-----" << endl;
	Book book("좋은 C++", "555-12345-890-0", 20000);
	book.ShowBookInfo();
	cout << endl;
	Book book1(book);
	book1.ShowBookInfo();
	cout << endl;
	Book book2("???", "???", 0);
	book2 = book;
	book2.ShowBookInfo();
	cout << endl << "-----EBook-----" << endl;
	EBook ebook("좋은 C++ ebook", "555-12345-890-1", 10000, "fdx9w0i8kiw");
	ebook.ShowEBookInfo();
	cout << endl;
	EBook ebook1(ebook);
	ebook1.ShowEBookInfo();
	cout << endl;
	EBook ebook2("???", "???", 0, "???");
	ebook2 = ebook;
	ebook2.ShowEBookInfo();

	return 0;
}
