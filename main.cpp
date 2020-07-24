#include <iostream>
#include <string>
#include "algorithms.h"
#include "fifo.h"
#include "lru.h"
#include "lfu.h"
#include "ran.h"

using namespace coen383;

algorithms* getAlgo(std::string algoFlag);

int main(int argc, char *argv[])
{

	if(argc < 3)
	{
		std::cerr<<"Improper usage! Provide size of page table as argument."<<std::endl;
		return -1;
  }
    
  std::string algoFlag = argv[1];
  std::string str2 = argv[2];
  std::string input;
  int tableSize = stoi(str2);
  
  //create base class reference to child class
  //enables runtime polymorphism 
  algorithms * algo = getAlgo(algoFlag);
  if (algo == NULL){std::cerr<<"Invalid flag!"<<std::endl; return 0;}

  //set tableSize
  if(tableSize > algo->MAX_SIZE)
  {
     std::cerr<<"Error: table size too large!"<<std::endl;
     return 0;
  }
  else
    algo->setTableSize(tableSize);
	
	std::cerr<<"Enter page number: "<<std::endl;

	while(std::cin>>input)
	{
		if(!isalpha(input.at(0)))
		{
      algo->setPageRequest(stoi(input));
      algo->pageReplaceAlgo();
    }
  }
  std::cerr<<algo->getCount()<<std::endl;
  algo->getFile().close();

	return 0;
}

//function definitions 

algorithms* getAlgo(std::string algoFlag)
{
  if (algoFlag == "-fifo" || algoFlag == "-FIFO")
    return new fifo();
  else if (algoFlag == "-lru" || algoFlag == "-LFU")
  {
    return new lru();
  }  
  else if (algoFlag == "-lfu" || algoFlag == "-LFU")
  {
    return new lfu();
  }
  // else if (algoFlag == "-ran" || algoFlag == "-RAN")
  // {
  //   return new ran();
  // }
  else
    return NULL;
}
