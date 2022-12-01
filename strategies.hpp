/*
CSCE 2110 Section 002/213
Group 6 - Project 2
Rock Paper Scissors
Description: Strategies Header
*/

#ifndef _STRATEGIES_HPP_
#define _STRATEGIES_HPP_

#include <random>
#include <vector>
#include <iostream>
#include <string>

#include "bays.hpp"

enum RPS{
  NOCHOICE = 0,
  ROCK = 1,
  PAPER = 2,
  SCISSORS = 3
};

class ucb_arm
{
  //in progress, for UCB strategy
};

// Both stretegies shouls return an enum

int playRPS(RPS p1_choice, RPS p2_choice);

RPS GroupStrategy(bays_arm& r, bays_arm& p, bays_arm& s,
  int p_choice, int p_result, bool debug);

RPS BigBadEvilCode(int lastResult);

RPS int_to_RPS(int it);

std::string RPS_to_s(RPS rps);

#endif
