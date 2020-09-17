#ifndef WAREHOUSE
#define WAREHOUSE

#include <string>
#include <fstream>
#include "HardcoverBook.h"
#include "PaperbackBook.h"
#include "LinkedList.h"

using namespace std;

class Warehouse{
     friend istream& operator >> (istream&, Warehouse&);
     
     friend ostream& operator << (ostream&, Warehouse&);

     public:
	static const long MAX_BOOKS = 100;

	Warehouse();
	~Warehouse();
	
	bool find(string, Book*);

     protected:
	bool createBook_(Book*);

     private:
	LinkedList<Book*> list_;
	long bookCount_;
};
#endif
