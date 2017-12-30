#include "algorithms.h"

#ifndef COEN_177_LRU_H
#define COEN_177_LRU_H

namespace coen177_lab4
{
  class lru: public algorithms
  {  
    public:
      //CONSTRUCTOR
      lru();
    
      //MEMBER MODIFICATION FUNCTIONS
      void pageReplaceAlgo();
    
    private:
      std::list <int> llist;
      std::map <int, std::list <int> :: iterator> table;
      std::map <int, std::list <int> :: iterator> :: iterator tableitr;
      std::list <int> :: iterator llistitr;
  };
}

#endif