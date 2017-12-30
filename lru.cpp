#include "lru.h"

namespace coen177_lab4
{
  //CONSTRUCTOR
  lru::lru()
  {
    pageRequest = 0;
    numElements = 0;
    pageNumber = 0;
    numCount = 0;
    //*used for debugging*//
    // myfile.open ("output");
  }

  void lru::pageReplaceAlgo() 
  {
    tableitr = table.find(pageRequest);
    if(tableitr == table.end())
    {
      //page does not already exist in the cache
      std::cout<<"Page number "<<pageRequest<<" caused a page fault."<<std::endl;
      myfile<<"Page number "<<pageRequest<<" caused a page fault.\n";

      llistitr = llist.insert(llist.begin(),pageRequest);
      table.insert(std::pair <int, std::list <int> :: iterator> (pageRequest,llistitr));

      if(table.size() > tableSize)
      {
        table.erase(llist.back());
        llist.pop_back();
      }
      numElements++;
      numCount++;
    }
    else
    {
      ///page already exists in the cache
      std::cerr<<"Page number "<<pageRequest<<" caused a page hit."<<std::endl;

      //remove node from list and remove pair element in table 
      llist.erase(table[pageRequest]);
      table.erase(tableitr);

      //make new node and pair with value and insert at the beginning of the list 
      llistitr = llist.insert(llist.begin(),pageRequest);
      table.insert(std::pair <int, std::list <int> :: iterator> (pageRequest,llistitr));
    }
    //*used for debugging*//

    // std::cerr<<"llist: ";
    // for (std::list<int>::const_iterator it = llist.begin(); it != llist.end(); ++it)
    //   std::cerr<<*it<<" ";
    // std::cerr<<std::endl;
  }
}