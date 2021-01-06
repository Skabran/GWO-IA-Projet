#ifndef SOLUTION_H
#define SOLUTION_H
#include "Problem.h"


#include <vector>
using namespace std;

class Solution
{
public:
    Solution (Problem& pbm);
    Solution (Solution& sol);
    ~Solution();

    Problem& pbm() const;

    Solution& operator=  (const Solution& sol);
    bool operator== (const Solution& sol) const;
    bool operator!= (const Solution& sol) const;

    void initialize();
    double fitness(int numfunction);
    double get_fitness() const;

    static const int ROSENBROCK;
    static const int RASTRIGIN;
    static const int ACKLEY;
    static const int SCHWEFFEL;
    static const int SCHAFFER;
    static const int WEIERSTRASS;

    vector<double> solution() const;

    double& position(const int index);
    void  position(const int index, const double value);


private:
    vector<double> _solution;   //coordonnees de chaques solution. Sa taille est le nb de dimensions
    double _current_fitness;
    Problem& _pbm;
};
#endif // SOLUTION_H
