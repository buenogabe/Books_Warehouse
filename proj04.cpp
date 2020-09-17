#include <iostream>
#include <string>
#include <cstring>
#include "Warehouse.h"
#include <fstream>
#include "Book.h"

using namespace std;

int main(int argc, char* argv[])
{
   
   ifstream inputFile;
   inputFile.open(argv[1]);
   if(inputFile.fail())
   {
      cout << "input file not found" << endl;
      return -1;
   }
   Warehouse ware;
   inputFile >> ware;
   string isbn; 
   Book* book = new PaperbackBook();
   if(argc < 3 || !(!strcmp(argv[2], "find") || !strcmp(argv[2], "list") ))
   {
      cout << "./proj04 <input file> find <isbn>" << endl;
      cout << " ./proj04 <input file> list" << endl;
      return -1;
   }
   if(argc ==1)
   {
      cout << "./proj04 <input file> find <isbn>" << endl;
      cout << " ./proj04 <input file> list" << endl;
      return -1;
   }

   else if(!strcmp(argv[2], "list"))
   {
      cout << ware << endl;
   }
   
   else if(!strcmp(argv[2], "find"))
   {
      if(ware.find(argv[3], book)) {
	cout << " -- FOUND:\n";
        cout << *book;
	} else {
	cout << " -- NOT FOUND!!\n";
	}
   }
      
   inputFile.close();
   return 0;





}
