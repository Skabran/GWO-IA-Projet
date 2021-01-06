#include "Solution.h"
#include <vector>
#include <random>
#include <cmath>
using namespace std;

const int Solution::ROSENBROCK = 1;
const int Solution::RASTRIGIN = 2;
const int Solution::ACKLEY = 3;
const int Solution::SCHWEFFEL = 4;
const int Solution::SCHAFFER = 5;
const int Solution::WEIERSTRASS = 6;

Solution::Solution (Problem& pbm): _pbm{pbm}, _current_fitness{0.0}, _solution{0.0}
{}
Solution::Solution (Solution& sol): _pbm{sol.pbm()}, _current_fitness{sol.get_fitness()}, _solution{sol.solution()}
{}
Solution::~Solution()
{}

Solution& Solution::operator=  (const Solution& sol)
{
  _solution=sol.solution();
  _current_fitness=get_fitness();
  _pbm=pbm();
  return *this;
}
bool Solution::operator== (const Solution& sol) const
{
    return (_solution==sol.solution()&&_current_fitness==get_fitness()&&_pbm==pbm());
}
bool Solution::operator!= (const Solution& sol) const
{
    return (_solution!=sol.solution()||_current_fitness!=get_fitness()||_pbm!=pbm());
}

void Solution::initialize()
{
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> distr( _pbm.get_lowerLimit(), _pbm.get_upperLimit());

    _solution.resize(0);

    for(int n=0; n< _pbm.dimension(); ++n)
    {
      _solution[n] = distr(gen);
    }
}
double Solution::fitness(int numfunction)
{
  if (numfunction == ROSENBROCK)
  {
    double sum = 0;

    for (int i = 0; i < _pbm.dimension() - 1 ; ++i)
    { sum += 100 * pow(( _solution[i+1] - pow( _solution[i],2)),2) + pow(( _solution[i] - 1),2); }

    return sum;
  }
  else if(numfunction == RASTRIGIN)
  {
    double sum = 0;

    for (int i = 0; i < _pbm.dimension() ; ++i)
    { sum += 100 * pow( _solution[i],2) - 10*cos(2*M_PI*_solution[i]); }

    return 10*_pbm.dimension() + sum;
  }
  else if(numfunction == ACKLEY)
  {
    double sum1 = 0;
    double sum2 = 0;


    for (int i = 0; i <  _pbm.dimension(); ++i)
    { sum1 += pow( _solution[i],2); sum2 += cos(2.0*M_PI*_solution[i]); }

    return - (20.0 * exp ((-0.2) * sqrt(sum1/ _pbm.dimension()))) - exp(sum2/ _pbm.dimension()) + 20.0 + exp(1.0);

  }
  else if(numfunction == SCHWEFFEL)
  {
    double sum = 0;

    for (int i = 0; i < _pbm.dimension(); ++i)
   { sum +=  _solution[i]*sin( sqrt( abs(_solution[i]) )); }

   return 418.9829*_pbm.dimension() - sum;
  }
  else if(numfunction == SCHAFFER)
  {
    double sum = 0;

    for (int i = 0; i < _pbm.dimension() - 1 ; ++i)
    { sum += 0.5 + ( sin((pow(pow(_solution[i+1],2) - pow(_solution[i],2),2))) - 0.5 ) / ( 1 + 0.001*pow((pow(_solution[i+1],2) + pow(_solution[i],2)),2)); }

    return sum;
  }
  else if(numfunction == WEIERSTRASS)
  {
    double sum1 = 0;
    double sum2 = 0;
    double sum3 = 0;

    for (int i = 0; i <  _pbm.dimension(); ++i)
    {
      for (int k = 0; k < 20; ++k)
      {
          sum2 += pow(0.5,k) * cos(2.0 * M_PI * pow(3,k) * (_solution[i] + 0.5));
      }

      sum1 += sum2;
      sum2 = 0;
    }

    for (int k = 0; k < 20; ++k)
      {
          sum3 += pow(0.5,k) * cos(2.0 * M_PI * pow(3,k) * 0.5);
      }

    return sum1 -  _pbm.dimension()*sum3;
  }
}

double& Solution::position(const int index)
{
  return _solution[index];
}

void  Solution::position(const int index, const double value)
{
  _solution[index] = value;
}

Problem& Solution::pbm() const{
    return _pbm;
}


double Solution::get_fitness() const{
    return _current_fitness;
}


vector<double> Solution::solution() const{
    return _solution;
}
