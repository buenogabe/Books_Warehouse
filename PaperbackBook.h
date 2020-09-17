#ifndef PAPERBACKBOOK
#define PAPERBACKBOOK

#include "Book.h"

class PaperbackBook : public Book {
     public:
	PaperbackBook();
	virtual ~PaperbackBook();

     protected:
	virtual string getCoverType() const;

};
#endif
