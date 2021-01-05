#include "optimizationAlgorithm.h"
#include <cmath>
#include <vector>
#include "Problem.h"
#include "Solution.h"

//pour le générateur aléatoire
#include <time.h>
#include <stdio.h>
#include <stdlib.h>

using namespace std;




void optimizationAlgorithm::evolution(int a){
    for(unsigned int solutionIndex=0; solutionIndex<_population.size(); solutionIndex++){
        for(unsigned int coordoneeIndex=0; coordoneeIndex<_population.solution().size(); coordoneeIndex++){
            double r1 = rand()/RAND_MAX;
            double r2 = rand()/RAND_MAX;

            double A1=2.0*a*r1-a;
            double C1=2.0*r2;

            double D_alpha= std::abs(C1*_population[_alpha_index][coordoneeIndex]-_population[solutionIndex][coordoneeIndex]);
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


void optimizationAlgorithm::initialize(){
    for (unsigned int i=0; i<_population.size(); i++){
        _population[i].initialize();
    }

}

void optimizationAlgorithm::evaluate(){

    srand(time(0));

    double a;

    for(int iteration=0; iteration<_setup.nb_evolution_steps(); iteration++){

        a = 2.0 * iteration(2.0/_maximum_iterations);

        _fitness_values=fitness_values();

        evolution(iteration);

        _best_fitness_over_time[iteration]=_alpha_score;    //On garde le meilleur score de cette itération
        if(_alpha_score<best_cost()) //Si le score de cette itération est inférieur au meilleur score jamais trouvé
        {
            _best_solution=_population[_alpha_index];
        }

    }


}

vector<double>&  optimizationAlgorithm::fitness_values(){

        //calcule la fonction objectif de chaque solutions
        for(unsigned int i=0; i<_population.size(); i++){
            _fitness_values[i]=_population[i].fitness(_population.pbm().get_numfunction());



        }

    //Met a jour Alpha, Beta et Delta
    if(_fitness_values[i] < _alpha_score){
        _alpha_score=_fitness_values[i];    //Mise a jour du score d'Alpha
        _alpha_index=i;                     //Mise a jour de la position d'Alpha
    }
    else if(_fitness_values[i] > _alpha_score) && (_fitness_values[i]<_beta_score){
        _beta_score=_fitness_values[i];    //Mise a jour du score de Beta
        _beta_index=i;                    //Mise a jour de la position de Beta
    }
    else if(_fitness_values[i] > _alpha_score) && (_fitness_values[i]>_beta_score) && (_fitness_values[i]<_delta_score){
        _delta_score=_fitness_values[i];    //Mise a jour du score de Delta
        _delta_index=i;                    //Mise a jour de la position de Delta
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




