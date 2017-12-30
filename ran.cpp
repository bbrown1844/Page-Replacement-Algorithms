#include "ran.h"

namespace coen177_lab4
{
  //CONSTRUCTOR
  ran::ran()
  {
    pageRequest = 0;
    numElements = 0;
    pageNumber = 0;
    numCount = 0;
    srand ( time(NULL) );
    //*used for debugging*//
    // myfile.open ("output");
  }

  void ran::pageReplaceAlgo() 
  {
    setItr = set.find(pageRequest);
    if(setItr == set.end())
    {    
      //page does not already exist in the cache
      std::cout<<"Page number "<<pageRequest<<" caused a page fault."<<std::endl;
      //*used for debugging*//
      // myfile<<"Page number "<<pageRequest<<" caused a page fault.\n";
      if(set.size() >= tableSize)
      {
        std::set<int>::const_iterator it = set.begin();
        int count = rand()%tableSize;
        for (int i = 0; i < count; i++)
          ++it;
        set.erase(it);
      }
      set.insert(pageRequest);
      numCount++;
    }
    else
    {
      std::cerr<<"Page number "<<pageRequest<<" caused a page hit."<<std::endl;
    }
    //*used for debugging*//

    // std::cerr<<"set: ";
    //  for (setItr = set.begin(); setItr != set.end(); ++setItr)
    // {
    //     std::cerr << '\t' << *setItr;
    // }
    // std::cerr<<std::endl;
  }

}