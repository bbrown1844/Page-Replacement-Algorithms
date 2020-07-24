#include "algorithms.h"

#ifndef COEN_383_RAN_H
#define COEN_383_RAN_H

namespace coen383
{
  class ran: public algorithms
  {  
    public:
      //CONSTRUCTOR
      ran();
    
      //MEMBER MODIFICATION FUNCTIONS
      void pageReplaceAlgo();
    
    private:
      std::set<int, std::greater <int> >set;
      std::set<int, std::greater <int> > :: iterator setItr;
  };
}

#endif