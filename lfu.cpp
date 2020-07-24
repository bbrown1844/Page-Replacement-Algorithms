#include "lfu.h"

namespace coen383
{
  //CONSTRUCTOR
  lfu::lfu()
  {
    pageRequest = 0;
    numElements = 0;
    pageNumber = 0;
    numCount = 0;
    //*used for debugging*//
    // myfile.open ("output");
  }
  
  void lfu::pageReplaceAlgo()
  {
    pageItr = page.find(pageRequest);
    if(pageItr == page.end())
    {
      //page does not already exist in the cache
      std::cout<<"Page number "<<pageRequest<<" caused a page fault."<<std::endl;
      myfile<<"Page number "<<pageRequest<<" caused a page fault."<<std::endl;

      if(page.size() >= tableSize)
      {
        occItr = count.lower_bound(0);
        counter = occItr->second;
        count.erase(occItr);
        page.erase(counter);
      }
      page.insert(std::pair <int, std::multimap<int, int> :: iterator> (pageRequest,count.insert(std::pair <int, int> (1, pageRequest))));
      numCount++;
    }
    else
    {
      //page already exists in the cache
      std::cerr<<"Page number "<<pageRequest<<" caused a page hit."<<std::endl;
      //get occurence of the page 
      counter = pageItr->second->first;
      //remove page from occurences 
      count.erase(pageItr->second);
      //insert iterator for the page(key) as the page(value), which points to occurence of that page in occurence
      pageItr->second = count.insert(std::make_pair (++counter, pageRequest));
    }
    //*used for debugging*//

    // std::cerr<<"count: ";
    // for (std::multimap <int, int> ::const_iterator it = count.begin(); it != count.end(); ++it)
    //   std::cerr<<"< "<<it->first<<","<<it->second<<"> ";
    // std::cerr<<std::endl;
  }   
    
}