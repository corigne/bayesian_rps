/*
Description: UCB Strategy Header
*/

#ifndef _UCB_HPP_
#define _UCB_HPP_

#include <random>

class ucb_arm
{
  private:
    double conf_lvl;
    unsigned long n_tries;  
    double mean_reward;
    double uncertainty;
    
    double get_uncert(unsigned long timestep);
    
  public:
    ucb_arm();
    ucb_arm(double conf_lvl);
    void initialize(double conf_lvl);
    double sample(unsigned long timestep);
    void update(bool lastWon);
  
};

#endif