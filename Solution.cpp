#include "Solution.h"
#include <vector>
using namespace std;

Solution::Solution (const Problem& pbm): _pbm{pbm}, _current_fitness{0.0}, _solution{0.0}
{}
Solution::Solution (const Solution& sol): _pbm{sol.pbm()}, _current_fitness{sol.get_fitness()}, _solution{sol.solution()}
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
  //INITIALISATION ALEATOIRE DE _solution
}
double Solution::fitness(int numfunction)
{
  //CALCUL DE FITNESS, LE NUMERO EN PARAMETRE EST LE IDENTIFIANT DE LA FONCTION BENCHMARK
}

double& Solution::position(const int index)
{
  return _solution[index];
}

void  Solution::position(const int index, const double value)
{
  _solution[index] = value;
}

const Problem& Solution::pbm() const{
    return _pbm;
}


double Solution::get_fitness() const{
    return _current_fitness;
}


vector<double>& Solution::solution() const{
    return _solution;
}


