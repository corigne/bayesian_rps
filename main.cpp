/*
CSCE 2110 Section 002/213
Group 6 - Project 2
Rock Paper Scissors
Description: Main Function
*/

// Includes
#include "master.hpp"

// Main Function

int main(int argc, char* argv[])
{
  bool NOARGS = argc <= 1;
  bool DEBUG = argc > 2 && !std::strcmp(argv[2], "-DEBUG");
  
  if(DEBUG)
  {
    std::cout << "**** DEBUG MODE ACTIVE ****" << std::endl;
  }
  
  if(!NOARGS)
  {
    //DO STUFF
  }
  else
  {
    std::cout << "No arguments provided. Please enter the number of trials "
      << " to run as an argument." << std::endl;
  }
  
  
      
  
  return 0;
}
