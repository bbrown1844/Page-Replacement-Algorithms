#include "fifo.h"

namespace coen383
{
  //CONSTRUCTOR
  fifo::fifo()
  {
    pageRequest = 0;
    numElements = 0;
    pageNumber = 0;
    numCount = 0;
    //*used for debugging*//
    //myfile.open ("output");
  }
  
  void fifo::pageReplaceAlgo()
  {
    setItr = set.find(pageRequest);
    if(setItr == set.end())
    {
      //page does not already exist in the cache
      std::cout<<"Page number "<<pageRequest<<" caused a page fault."<<std::endl;
      // myfile<<"Page number "<<pageRequest<<" caused a page fault.\n";

      if(llist.size() >= tableSize)
      {
        set.erase(llist.back());
        llist.pop_back();
      }
        
      llist.push_front(pageRequest);
      set.insert(pageRequest);
      numCount++;
    }
    else
      std::cerr<<"Page number "<<pageRequest<<" caused a page hit."<<std::endl;

    //*used for debugging*//

    // std::cerr<<"llist: ";
    // for (std::list<int>::const_iterator it = llist.begin(); it != llist.end(); ++it)
    //   std::cerr<<*it<<" ";
    // std::cerr<<std::endl;
  }   
    
}