#include "Problem.h"
using namespace std;

Problem::Problem(int dim, int numfunction): _dimension{dim}, _lowerLimit{0.0},
_upperLimit{0.0}, _numfunction{numfunction}
{
   switch(numfunction)
   {
   case 1:
    _lowerLimit=-5.0;
    _upperLimit=10.0;
    case 2:
    _lowerLimit=-5.12;
    _upperLimit=5.12;
    case 3:
    _lowerLimit=-32.0;
    _upperLimit=32.0;
    case 4:
    _lowerLimit=-500.0;
    _upperLimit=500.0;
    case 5:
    _lowerLimit=-100.0;
    _upperLimit=100.0;
    case 6:
    _lowerLimit=-2.0;
    _upperLimit=2.0;
   }

}

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
