/*
CSCE 2110 Section 002/213
Group 6 - Project 2
Rock Paper Scissors
Description: Main Function
*/

#ifndef _DEBUG_HPP_
#define _DEBUG_HPP_

#include <iostream>
#include "tracker.hpp"

void DEBUG(unsigned long& num_rounds, tracker& record)
{
  for(unsigned long i = 0; i < num_rounds; i++)
        {
          if(i % 2 == 0)
          {
            record.record_game(1);
            std::cout << ".";
            if(i == 80) std::cout << std::endl;
          }
          else
          {
            record.record_game(-1);
            std::cout << "-";
          }
        }
        std::cout << std::endl;
}

#endif