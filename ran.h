#include "algorithms.h"

#ifndef COEN_177_RAN_H
#define COEN_177_RAN_H

namespace coen177_lab4
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