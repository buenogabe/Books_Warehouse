#include "Warehouse.h"
#include <iostream>

Warehouse::Warehouse() {
     bookCount_ = 0;
}

Warehouse::~Warehouse() {
     bookCount_ = 0;
}

istream& operator>> (istream& input, Warehouse& warehouse) {
     Book* bookptr = new PaperbackBook();
	while(input >> *bookptr) {
             if(warehouse.bookCount_ > warehouse.MAX_BOOKS)
		break;
		warehouse.createBook_(bookptr);
	}
	return input;
}

ostream& operator<< (ostream& output, Warehouse& warehouse) {
     for(int i = 0; i < warehouse.bookCount_; i++) {
	Book* bookptr;
     bookptr = warehouse.list_.data();
	output << *bookptr << endl;
	warehouse.list_.advance();
     }
     warehouse.list_.resetIterator();
     return output;
}

bool Warehouse::find(string isbn, Book* book) {
     for(int i =0; i < list_.length(); i++) {
	if(list_.data()->getISBN() == isbn) {
	     *book = *list_.data();
	     list_.resetIterator();
	     return true;
	}
	list_.advance();
     }
     list_.resetIterator();
     return false;
}

bool Warehouse::createBook_(Book* bookptr) {
     Book* temp;
     if(bookptr->getHardcover()) {
	temp = new HardcoverBook();
     } 
     else {
	temp = new PaperbackBook();
     }
     *temp = *bookptr;
     list_.insert(temp);
     bookCount_++;
     return true;
}
