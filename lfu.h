#include "algorithms.h"

#ifndef COEN_177_LFU_H
#define COEN_177_LFU_H

namespace coen177_lab4
{
  class lfu: public algorithms
  {  
    public:
      //CONSTRUCTOR
      lfu();

      //MEMBER MODIFICATION FUNCTIONS
      void pageReplaceAlgo();   

    private:
      int counter;
      std::multimap <int, int> :: iterator occItr;
      std::multimap <int, int> count;
      std::unordered_map<int, std::multimap<int, int> :: iterator> page;
      std::unordered_map<int, std::multimap<int, int> :: iterator> :: iterator pageItr;

  };
}

#endif