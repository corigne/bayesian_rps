/*
CSCE 2110 Section 002/213
Author: Nathan Jodoin
Rock Paper Scissors
Description: UCB Strategy Header
*/

#include "ucb.hpp"
#include <limits>

ucb_arm::ucb_arm()
{
  this->initialize(2.0);
}

ucb_arm::ucb_arm(double conf_lvl)
{
  this->initialize(conf_lvl);
}

void ucb_arm::initialize(double conf_lvl)
{
  this->n_tries = 0;
  this->mean_reward = 0;
  this->conf_lvl = conf_lvl;
}

double ucb_arm::get_uncert(unsigned long timestep)
{
  if(n_tries == 0)
  {
    return std::numeric_limits<double>::infinity();
  }
  else
  {
    // returns an uncertainty value that grows over time
    // but drops when tried
    return conf_lvl * sqrt(log(timestep) / n_tries);
  }
}

double ucb_arm::sample(unsigned long timestep)
{ 
  return mean_reward + get_uncert(timestep);
}

void ucb_arm::update(bool lastWon)
{
  this->n_tries += 1;
  //calculate the expected reward based on average of previous and last result
  this->mean_reward = (1 - 1.0/n_tries) * mean_reward + (1.0/n_tries) * lastWon;
}