/*
CSCE 2110 Section 002/213
Group 6 - Project 2
Rock Paper Scissors
Description: Strategies
*/
#include "strategies.hpp"
#include <random>

int playRPS(RPS p1, RPS p2)
{
  int result = 0;
  //return 1 for a win, 0 for a tie, -1 for a loss
  switch(p1)
  {
    case NOCHOICE:
    {
      result = -1;
      std::cout << "NO CHOICE MADE BY P1 IN GAME ERROR" << std::endl;  
    }
    
    case ROCK:
    {
      if(p2 == PAPER)
        result = -1;
        
      if(p2 == SCISSORS)
        result = 1;
        
      if(p2 == ROCK)
        result = 0;
        
      break;
    }
    
    case PAPER:
    {
      if(p2 == SCISSORS)
        result = -1;
        
      if(p2 == ROCK)
        result = 1;
      
      if(p2 == PAPER)
        result = 0;
        
      break;
    }
    
    case SCISSORS:
    {
      if(p2 == ROCK)
        result = -1;
        
      if(p2 == PAPER)
        result = 1;
        
      if(p2 == SCISSORS)
        result = 0;
        
      break;
    }
  }
  
  std::cout << "P1 chose " << RPS_to_s(p1) << ", P2 chose " 
    << RPS_to_s(p2) << ", RESULT: ";
  
  if(result == 1)
    std::cout << "Player 1 wins!" << std::endl;
  if(result == 0)
    std::cout << "Both players tied!" << std::endl;
  if(result == -1)
    std::cout << "Player 2 wins!" << std::endl;
  
  return result;
}

RPS GroupStrategy(bays_arm& r, bays_arm& p, bays_arm& s,
  int p_choice, int p_result, bool debug){
  
  if(p_choice == 0)
  {
    r.initialize(1.0, 1.0);
    p.initialize(1.0, 1.0);
    s.initialize(1.0, 1.0);
    
    return int_to_RPS(rand()%2 + 1);
  }
  else
  {
    bool prevWon = (p_result == 1 || p_result == 0);
    switch(p_choice)
    {
      case ROCK:
        r.update(prevWon);
        break;
    
      case PAPER:
        p.update(prevWon);
        break;
    
      case SCISSORS:
        s.update(prevWon);
        break;
    }

    std::vector<double> samples;
    samples.push_back(r.sample());
    samples.push_back(p.sample());
    samples.push_back(s.sample());
    RPS choice;
  
    double max = 0;
    unsigned int max_index = 0;
    //find highest sample
    for(unsigned int i = 0; i < samples.size() ; i++)
    {
      if(samples[i] > max){
        max = samples[i];
        max_index = i;
      }
    }

    // 0+1, ROCK, 1+1 PAPER, 2+1 SCISSORS
    choice = int_to_RPS(max_index+1);
    
    if(debug)
    {
      switch(choice)
      {
        case NOCHOICE:
          std::cout << "NO CHOICE MADE, ERROR" << std::endl;
          break;
      
        case ROCK:
          std::cout << "Bays chose ROCK" << std::endl;
          break;
      
        case PAPER:
          std::cout << "Bays chose PAPER" << std::endl;
          break;
      
        case SCISSORS:
          std::cout << "Bays chose SCISSORS" << std::endl;
          break;
      
      }
    }
    return choice;
  }
}

RPS BigBadEvilCode(ucb_arm& r, ucb_arm& p, ucb_arm& s, bool debug,
  int p_choice, int p_result, long curr_round){
  
  // RANDOM CHOICE
  // RPS choice = int_to_RPS(gen()%2 + 1);
  // std::mt19937 gen(rand());
  
  //RUNER UP
  

  if(p_choice == 0)
  {    
    return int_to_RPS(rand()%2 + 1);
  }
  else
  {
    bool prevWon = (p_result == 1 || p_result == 0);
    switch(p_choice)
    {
      case ROCK:
        r.update(prevWon);
        break;
    
      case PAPER:
        p.update(prevWon);
        break;
    
      case SCISSORS:
        s.update(prevWon);
        break;
    }

    std::vector<double> samples;
    samples.push_back(r.sample(curr_round));
    samples.push_back(p.sample(curr_round));
    samples.push_back(s.sample(curr_round));
    RPS choice;
  
    double max = 0;
    unsigned int max_index = 0;
    //find highest sample
    for(unsigned int i = 0; i < samples.size() ; i++)
    {
      if(samples[i] > max){
        max = samples[i];
        max_index = i;
      }
    }

    // 0+1, ROCK, 1+1 PAPER, 2+1 SCISSORS
    choice = int_to_RPS(max_index+1);
    
    if(debug)
    {
      switch(choice)
      {
        case NOCHOICE:
          std::cout << "NO CHOICE MADE, ERROR" << std::endl;
          break;
      
        case ROCK:
          std::cout << "UCB chose ROCK" << std::endl;
          break;
      
        case PAPER:
          std::cout << "UCB chose PAPER" << std::endl;
          break;
      
        case SCISSORS:
          std::cout << "UCB chose SCISSORS" << std::endl;
          break;
      
      }
    }
  return choice;
  }
}

RPS int_to_RPS(int it)
{
  switch(it)
  {
    case 0:
      return NOCHOICE;
      break;
    
    case 1:
      return ROCK;
      break;
    
    case 2:
      return PAPER;
      break;
    
    case 3:
      return SCISSORS;
      break;
    
    default:
      std::cout << "You entered something wrong (int_to_RPS) ROCK!" << std::endl;
      return ROCK;
  };
}

std::string RPS_to_s(RPS rps)
{
  switch(rps)
  {
    case ROCK:
      return "ROCK";
      break;
    
    case PAPER:
      return "PAPER";
      break;

    case SCISSORS:
      return "SCISSORS";
      break;
    
    case NOCHOICE:
      return "NOCHOICEMADEERROR";
      break;
    
  }
}
