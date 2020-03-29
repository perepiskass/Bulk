
#include "bulk.h"
#include <csignal>


Bulk* bulkPtr;
int countBulk;
void checkArg(int, char**);

void signalFunction(int sig)
{
  std::cout << std::endl;
  if (sig == 2)
  {
    if (bulkPtr->getQuantity()) bulkPtr->printData();
  }
  exit(0);
}
 
int main(int argc, char *argv[]) 
{
  try
  {
    checkArg(argc,argv);

    Bulk bulk(countBulk);
    bulkPtr = &bulk;
    std::string str;
    
    signal(SIGINT,signalFunction);

      while(getline(std::cin,str))
      {
        bulk.setData(std::move(str));
      }
  }
  
  catch(const std::exception& e)
  {
    std::cerr << e.what() << '\n';
  }

    return 0;
}

