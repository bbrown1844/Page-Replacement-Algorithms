#include <utility>
#include <map>
#include <iterator>
#include <list>
#include <unordered_set>
#include <set>
#include <unordered_map> 
#include <iostream>
#include <fstream>
#include <time.h>

#ifndef COEN_383_ALGORITHMS_H
#define COEN_383_ALGORITHMS_H

namespace coen383
{
  class algorithms
  {  
    public:
      static const int MAX_SIZE = 500;
      //CONSTRUCTOR 
      algorithms(){}
      //DESTRUCTOR
      ~algorithms(){}

      //MEMBER MODIFICATION FUNCTIONS
      // virtual int isInMemory() = 0;
      virtual void pageReplaceAlgo() = 0;
      
      //Set function
      void setPageRequest(int set) {pageRequest = set;}
      void setTableSize(int set) {tableSize = set;}

      //Get functions
      int getPageRequest() {return pageRequest;}
      int getNumElements() {return numElements;}
      int getPageNumber() {return pageNumber;}
      int getTableSize() {return tableSize;}
      int getCount() {return numCount;}
      std::ofstream& getFile() {return myfile;}

    protected: 
      int pageRequest, numElements, pageNumber, tableSize;
      int numCount;
      //*used for debugging*// 
      std::ofstream myfile;
  };
}

#endif