#include "optimizationAlgorithm.h"
#include <vector>
#include "Solution.h"
#include <cmath>




void optimizationAlgorithm::evolution(int iter){
    double a= 2.0 - iter*(2.0/MAXIMUM_ITERATION /* trouver ou elle se trouve et son nom */);
    for(unsigned int solutionIndex=0; solutionIndex<_population.size(); solutionIndex++){
        for(unsigned int coordoneeIndex=0; coordoneeIndex<_population._solution.size(); coordoneeIndex++){
            double r1 = /* fonction pour générer un nombre aléatoire entre 0 et 1*/;
            double r2 = /* fonction pour générer un nombre aléatoire entre 0 et 1*/;

            double A1=2.0*a*r1-a;
            double C1=2.0*r2;

            double D_alpha= std::abs(C1*/*SolutionAlpha*/[coordoneeIndex]-_population[solutionIndex][coordoneeIndex]);
            double X1 = /*SolutionAlpha*/[coordoneeIndex]-A1*D_alpha;
        }
    }
}

Solution& optimizationAlgorithm::solution(const unsigned int index) const {
    return _population[index];
}

double optimizationAlgorithm::fitness(const unsigned int index) const {
    return _fitness_values[index];
}

unsigned int optimizationAlgorithm::lower_cost() const {
    return _lower_cost;
}

unsigned int optimizationAlgorithm::upper_cost() const {
    return _upper_cost;
}

using namespace std;


