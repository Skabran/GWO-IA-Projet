#include "optimizationAlgorithm.h"
#include <cmath>
#include <vector>
#include "Problem.h"
#include "Solution.h"

//pour le générateur aléatoire
#include <time.h>
#include <stdio.h>
#include <stdlib.h>



void optimizationAlgorithm::evolution(int a){
    for(unsigned int solutionIndex=0; solutionIndex<_population.size(); solutionIndex++){
        for(unsigned int coordoneeIndex=0; coordoneeIndex<_population._solution.size(); coordoneeIndex++){
            double r1 = rand()/RAND_MAX;
            double r2 = rand()/RAND_MAX;

            double A1=2.0*a*r1-a;
            double C1=2.0*r2;

            double D_alpha= std::abs(C1*_population{_alpha_index][coordoneeIndex]-_population[solutionIndex][coordoneeIndex]);
            double X1 = _population[_alpha_index][coordoneeIndex]-A1*D_alpha;

             r1 = rand()/RAND_MAX;
             r2 = rand()/RAND_MAX;

            double A2=2.0*a*r1-a;
            double C2=2.0*r2;

            double D_beta= std::abs(C1*_population{_beta_index][coordoneeIndex]-_population[solutionIndex][coordoneeIndex]);
            double X2 = _population{_beta_index][coordoneeIndex]-A1*D_Beta;

            r1 = rand()/RAND_MAX;
            r2 = rand()/RAND_MAX;

            double A3=2.0*a*r1-a;
            double C3=2.0*r2;

            double D_delta= std::abs(C1*_population{_delta_index][coordoneeIndex]-_population[solutionIndex][coordoneeIndex]);
            double X3 = _population{_delta_index][coordoneeIndex]-A1*D_Delta;

            _population[solutionIndex][coordoneeIndex]=(X1+X2+X3)/3.0;
        }
    }
}

void optimizationAlgorithm::evaluate(){

    srand(time(0));

    double a;

    for(int iteration=0; iteration<_maximum_iterations; iteration++){

        a = 2.0 * iteration(2.0/_maximum_iterations);

        _fitness_values=fitness_values();

        evolution(iteration);


    }


}

vector<double>&  optimizationAlgorithm::fitness_values(){
//    double fitness;
//    double valeur;
//    double limiteInf;
//    double limiteSupp;
//    for(unsigned int solutionIndex=0; solutionIndex<_population.size(); solutionIndex++){
//        //Si un loup est en dehors des frontières on le remet à la limite pour chaque coordonnées
//        for(unsigned int coordoneeIndex=0; coordoneeIndex<_population[solutionIndex].size(); coordoneeIndex++){
//            valeur=_population[solutionIndex][coordoneeIndex];
//            limiteInf = _population[solutionIndex]._pbm.LowerLimit;
//            limiteSupp = _population[solutionIndex]._pbm.UpperLimit
//            if(valeur < limiteInf){
//                _population[solutionIndex][coordoneeIndex]= limiteInf;
//            }
//            if(valeur> limiteSupp){
//                _population[solutionIndex][coordoneeIndex]=limiteSupp;
//            }
//        }

        for(unsigned int i=0; i<_population.size(); i++){
            _population[i].fitness(_population.pbm().get_numfunction());
        }
    }
}


const vector<Solution*>& optimizationAlgorithm::solutions() const{
    return _population;
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


