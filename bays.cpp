/*
Author: Nathan Jodoin
Description: Bayesian Sampling Strategy Header
*/

#include "bays.hpp"

bays_arm::bays_arm(){
  //random device seeds the mersene twister for even random distribution
  gen = std::mt19937(dev());
    
}

void bays_arm::initialize(unsigned long alpha, unsigned long beta)
{
  this->alpha = alpha;
  this->beta = beta;
}

void bays_arm::update(bool lastWon)
{
  this->n_tries += 1;
  this->alpha += lastWon;
  this->beta += (1 - lastWon);
}

double bays_arm::sample()
{
  std::gamma_distribution<> gamma_alpha(this->alpha, 1.0);
  std::gamma_distribution<> gamma_beta(this->beta, 1.0);
  double A = gamma_alpha(gen);
  double B = gamma_beta(gen);
  return A / (A + B);
}