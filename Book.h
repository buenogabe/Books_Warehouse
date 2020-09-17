#ifndef BOOK
#define BOOK

#include <string>
#include <iomanip>
#include <fstream>
using namespace std;

class Book{
     friend istream& operator >> (istream&, Book&);
     friend ostream& operator << (ostream&, const Book&);
     
     public:
	static const int MAX_AUTHORS = 35;

	Book();
	virtual ~Book();
	string getPublisher() const;
	string getISBN() const;
	bool getHardcover() const;
	bool operator== (const Book&) const;
	Book* operator= (const Book&);
	bool operator> (const Book&) const; 
	virtual string getCoverType() const = 0;

     private:
	string title_;
	string authors_[Book::MAX_AUTHORS];
	short authorCount_;
	string publisher_;
	short yearPublish_;
	bool hardCover_;
	float price_;
	string isbn_;
	long copies_;
};
#endif
