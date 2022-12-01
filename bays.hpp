/*
CSCE 2110 Section 002/213
Author: Nathan Jodoin
Rock Paper Scissors
Description: Bayesian Sampling Strategy Header
*/
#ifndef _BAYS_HPP_
#define _BAYS_HPP_

#include <random>

class bays_arm
{
  private:
    std::random_device dev;
    std::mt19937 gen;
    unsigned long beta, alpha, n_tries;
    int prev_choide;
    
  public:
    bays_arm();
    void update(bool lastWon);
    double sample();
    void initialize(unsigned long alpha, unsigned long beta);
};
#endif