#include "Problem.h"
using namespace std;

Problem::Problem(int dim, double lowerLimit, double upperLimit, int numfunction): _dimension{dim}, _lowerLimit{lowerLimit},
_upperLimit{upperLimit}, _numfunction{numfunction}
{}

Problem::~Problem()
{}

int Problem::get_lowerLimit() const{
    return _lowerLimit;
}


int Problem::get_upperLimit() const{
    return _upperLimit;
}


int Problem::dimension() const{
    return _dimension;
}


int Problem::get_numfunction() const{
    return _numfunction;
}
