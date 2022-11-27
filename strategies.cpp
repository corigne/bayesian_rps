/*
CSCE 2110 Section 002/213
Group 6 - Project 2
Rock Paper Scissors
Description: Strategies
*/
#include "strategies.hpp"

int playRPS(RPS p1, RPS p2)
{
  //return 1 for a win, 0 for a tie, -1 for a loss
  switch(p1)
  {
    case ROCK:
    {
      if(p2 == PAPER)
        return -1;
        
      if(p2 == SCISSORS)
        return 1;
        
      if(p2 == ROCK)
        return 0;
        
      break;
    }
    
    case PAPER:
    {
      if(p2 == SCISSORS)
        return -1;
        
      if(p2 == ROCK)
        return 1;
      
      if(p2 == PAPER)
        return 0;
        
      break;
    }
    
    case SCISSORS:
    {
      if(p2 == ROCK)
        return -1;
        
      if(p2 == PAPER)
        return 1;
        
      if(p2 == SCISSORS)
        return 0;
        
      break;
    }
  }
  return 0;
}

RPS GroupStrategy(int lastResult){
  
  //debug choice
  RPS choice = ROCK;
  
  //GROUP MAIN STRATEGY
  return choice;
}

RPS BigBadEvilCode(int lastResult){
  
  //debug choice
  RPS choice = SCISSORS;
  
  //RUNER UP
  return choice;
}

