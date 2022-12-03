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
#include "ucb.hpp"

enum RPS{
  NOCHOICE = 0,
  ROCK = 1,
  PAPER = 2,
  SCISSORS = 3
};

// Both stretegies shouls return an enum

int playRPS(RPS p1_choice, RPS p2_choice);

RPS GroupStrategy(bays_arm& r, bays_arm& p, bays_arm& s,
  int p_choice, int p_result, bool debug);

RPS BigBadEvilCode(ucb_arm& r, ucb_arm& p, ucb_arm& s, bool debug,
  int p_choice, int p_result, long curr_round);

RPS int_to_RPS(int it);

std::string RPS_to_s(RPS rps);

#endif
