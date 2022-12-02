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
  bool b_NOARGS = argc <= 1;
  bool b_DEBUG = argc > 2 && !std::strcmp(argv[2], "-DEBUG");
  
  if(b_DEBUG)
  {
    std::cout << "**** DEBUG MODE ACTIVE ****" << std::endl;
  }
  
  //guard statement against no arguments provided at execution
  if(!b_NOARGS)
  {
    //guarge against negative #rounds
    if(std::stol(argv[1]) <= 0)
    {
      std::cout << "You entered a number of rounds < or = 0." << std::endl;
      std::cout << "When executing please oberve documentation." << std::endl;
      exit(1);
    }
    unsigned long num_rounds = std::stol(argv[1]);
  
    // Create a data structure to track wins, losses and ties for each algo.
    tracker record;
    
    //DEBUG TEST
    // currently splits 50/50 to test data structure and output
    if(b_DEBUG)
    {
      DEBUG(num_rounds, record);
    }else
    {
      //COMPETITIVE LOGIC
    
      int last_result;
      
      bays_arm rock, paper, scissors;
      
      bays_arm rock2, paper2, sciss2;
      
      RPS p1_choice = NOCHOICE, p2_choice = NOCHOICE;
    
      for(unsigned long i = 0; i < num_rounds; i++)
      {
      
        // last_result is:
        // 1 for Main Strat Win
        // -1 for BBEC / Runner Up Win
        // 0 for TIE
        std::cout << "Game " << i+1 << " ";
        p1_choice = GroupStrategy(rock, paper, scissors, p1_choice, 
          last_result, b_DEBUG);
        
        p2_choice = BigBadEvilCode(last_result);
        
        /*
        p2_choice = GroupStrategy(rock2, paper2, sciss2, p2_choice,
          last_result*-1, b_DEBUG);
        */
        int result = playRPS(p1_choice, p2_choice);
      
        last_result = result;
      
        record.record_game(result);
      }  
    }
    
    // Display the statistical results of the matches
    record.print_results();
    
  }
  else
  {
    //output error from NOARGS
    std::cout << "No arguments provided. Please enter the number of trials "
      << " to run as an argument." << std::endl;
    exit(1);
  }
  
  
  return 0;
}