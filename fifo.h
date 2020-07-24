#include "algorithms.h"

#ifndef COEN_383_FIFO_H
#define COEN_383_FIFO_H

namespace coen383
{
  class fifo: public algorithms
  {  
    public:
      //CONSTRUCTOR
      fifo();

      //MEMBER MODIFICATION FUNCTIONS
      void pageReplaceAlgo();   

    private:
      std::list <int> llist;
      std::unordered_set<int> set;
      std::unordered_set<int> :: iterator setItr;

  };
}

#endif