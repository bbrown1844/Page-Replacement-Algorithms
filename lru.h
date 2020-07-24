#include "algorithms.h"

#ifndef COEN_383_RAN_H
#define COEN_383_RAN_H

namespace coen383
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