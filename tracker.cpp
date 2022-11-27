/*
CSCE 2110 Section 002/213
Group 6 - Project 2
Rock Paper Scissors
Description: Win/Loss/Tie Datastructure Definition
*/
#include "tracker.hpp"
#include <iostream>

void tracker::P1_Win()
{
  p1.wins += 1;
}

void tracker::P2_Win()
{
  p2.wins += 1;
}

void tracker::Tie()
{
  ties += 1;
}

void tracker::record_game(int result)
{
  switch(result)
  {
    //win
    case 1:
    {
      this->P1_Win();
      break;
    }
    //loss
    case -1:
    {
      this->P2_Win();
      break;   
    }
    //tie
    case 0:
    {
      this->Tie();
      break;
    }
  }
}

void tracker::print_results() const
{
  //Prints the results after calculating the various metrics.
  unsigned long rounds = p1.wins + p2.wins + ties;
  long double pct_wins = (long double)p1.wins / rounds * 100;
  long double pct_ties = (long double)ties / rounds * 100;
  long double pct_losses = (long double)p2.wins / rounds * 100;
  
  std::cout << "Rounds: " << rounds << std::endl;
  std::cout << "Wins: " << p1.wins << " (" << pct_wins << "%)" << std::endl;
  std::cout << "Ties: " << ties << " (" << pct_ties << "%)" << std::endl;
  std::cout << "Losses: " << p2.wins << " (" << pct_losses << "%)" << std::endl;
}