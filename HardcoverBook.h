#ifndef HARDCOVERBOOK
#define HARDCOVERBOOK
#include "Book.h"

class HardcoverBook : public Book {
     public:
	HardcoverBook();
	virtual ~HardcoverBook();
     protected:
	virtual string getCoverType() const;
};
#endif 
