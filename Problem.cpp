#include "Problem.h"
using namespace std;

Problem::Problem(int dim, double lowerLimit, double upperLimit, int numfunction): _dimension{dim}, _lowerLimit{lowerLimit},
_upperLimit{upperLimit}, _numfunction{numfunction}
{}

Problem::~Problem()
{}

Problem& Problem::operator= (const Problem& pbm)
{
    _dimension = pbm.dimension();
    _lowerLimit = pbm.get_lowerLimit();
    _upperLimit = pbm.get_upperLimit();
    _numfunction = pbm.get_numfunction();
}

bool Problem::operator== (const Problem& pbm)
{
    return (_dimension == pbm.dimension()) && (_lowerLimit == pbm.get_lowerLimit()) && (_upperLimit == pbm.get_upperLimit()) && (_numfunction == pbm.get_numfunction());
}

bool Problem::operator!= (const Problem& pbm)
{
    return (_dimension != pbm.dimension()) || (_lowerLimit != pbm.get_lowerLimit()) || (_upperLimit != pbm.get_upperLimit()) || (_numfunction != pbm.get_numfunction());
}


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
