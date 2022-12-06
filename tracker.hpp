/*
Description: Win/Loss/Tie Datastructure Declaration
*/
#ifndef _TRACKER_HPP_
#define _TRACKER_HPP_

#include <string>
#include <iostream>

typedef struct player
{
  unsigned int wins;
}player;

class tracker
{
  private:
    player p1;
    player p2;
    unsigned int ties;
    void P1_Win();
    void P2_Win();
    void Tie();
   
  public:
    tracker()
    {
      //initialize values on the heap
      p1.wins = 0;
    
      p2.wins = 0;
    
      ties = 0;
    }
   
    void record_game(int result);
  
    void print_results(std::string p1_name, std::string p2_name) const;
};

#endif
