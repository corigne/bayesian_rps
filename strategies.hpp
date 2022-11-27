/*
CSCE 2110 Section 002/213
Group 6 - Project 2
Rock Paper Scissors
Description: Strategies Header
*/

#ifndef _STRATEGIES_HPP_
#define _STRATEGIES_HPP_

enum RPS{
  ROCK = 1,
  PAPER = 2,
  SCISSORS = 3
};

class rps_bay
{
  //in progress, for bayesian thompson sampling strategy
};

class rps_ucb
{
  //in progress, for UCB strategy
};

// Both stretegies shouls return an enum

RPS GroupStrategy();

RPS BigBadEvilCode();


#endif
