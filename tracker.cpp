/*
CSCE 2110 Section 002/213
Group 6 - Project 2
Rock Paper Scissors
Description: Win/Loss/Tie Datastructure Definition
*/
#include "tracker.hpp"

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

void tracker::print_results(std::string p1_name, std::string p2_name) const
{
  //Prints the results after calculating the various metrics.
  unsigned long rounds = p1.wins + p2.wins + ties;
  long double pct_wins = (long double)p1.wins / rounds * 100;
  long double pct_ties = (long double)ties / rounds * 100;
  long double pct_losses = (long double)p2.wins / rounds * 100;
  
  std::string winner, loser;
  
  if(p1.wins > p2.wins) // normal condition, we hope
  {
    winner = p1_name;
    loser = p2_name;
  }
  else if(p2.wins > p1.wins) // swap p1 and p2 stats in the event of p1 loss
  {
    winner = p2_name;
    loser = p1_name;
    long double temp = pct_wins;
    pct_wins = pct_losses;
    pct_losses = temp;
    
  }
  else // catches a pure tie, statistically improbable but still
  {
    std::cout << "It was a tie, how strange. Did someone cheat?" << std::endl;
    return;
  }
  
  std::cout << std:: endl;
  
  std::cout << "Rounds: " << rounds << std::endl;
  std::cout << "Wins: " << p1.wins << " (" << pct_wins << "%)" << std::endl;
  std::cout << "Ties: " << ties << " (" << pct_ties << "%)" << std::endl;
  std::cout << "Losses: " << p2.wins << " (" << pct_losses << "%)" << std::endl;
  
  std::cout << std::endl;
  
  std::cout << "Winning Algorithm: " << winner << std::endl;
  std::cout << "Win Pct: " << pct_wins << "%" << std::endl;
  std::cout << "Tie Pct: " << pct_ties << "%" << std::endl << std::endl;
  
  std::cout << "Losing Algorithm: " << loser << std::endl;
  std::cout << "Win Pct: " << pct_losses << "%" << std::endl;
  std::cout << "Tie Pct: " << pct_ties << "%" << std::endl << std::endl;
  
}