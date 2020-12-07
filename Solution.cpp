#include "Solution.h"
#include <vector>



const Solution::Problem& pbm() const{
    return _pbm;
}


double Solution::get_fitness() const{
    return _current_fitness;
}


vector<double>& Solution::solution() const{
    return _solution;
}

using namespace std;
