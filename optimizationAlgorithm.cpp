#include "optimizationAlgorithm.h"
#include <cmath>
#include <vector>
#include "Problem.h"
#include "Solution.h"
#include <random>       //pour le générateur aléatoire
#include <stdio.h>
#include <stdlib.h>

using namespace std;

optimizationAlgorithm::optimizationAlgorithm(const Problem& pbm, const SetUpParams& setup): _setup{setup}, _population{},
_alpha_index{0}, _alpha_score{INT_MAX}, _beta_index{0}, _beta_score{INT_MAX}, _delta_index{0}, _delta_score{INT_MAX},
_fitness_values{}, _best_fitness_over_time{}, _best_solution{}

{
    _fitness_values.resize(_setup.population_size());
    _best_fitness_over_time.resize(_setup.nb_evolution_steps());
    _population.resize(_setup.population_size());
    initialize();
}


void optimizationAlgorithm::evolution(int iter)
{
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> distr(0,1);

    double a = 2.0 * iter*(2.0/_setup.nb_evolution_steps());

    for(unsigned int solutionIndex=0; solutionIndex<_population.size(); solutionIndex++)
    {
        for(unsigned int coordoneeIndex=0; coordoneeIndex<_population[solutionIndex]->solution().size(); coordoneeIndex++)
        {
            double r1 = distr(gen);
            double r2 = distr(gen);

            double A1=2.0*a*r1-a;
            double C1=2.0*r2;

            double D_alpha= std::abs((C1*_population[_alpha_index]->position(coordoneeIndex))-_population[solutionIndex]->position(coordoneeIndex));
            double X1 = _population[_alpha_index]->position(coordoneeIndex)-A1*D_alpha;

            r1 = distr(gen);
            r2 = distr(gen);

            double A2=2.0*a*r1-a;
            double C2=2.0*r2;

            double D_beta= std::abs(C2*_population[_beta_index]->position(coordoneeIndex)-_population[solutionIndex]->position(coordoneeIndex));
            double X2 = _population[_beta_index]->position(coordoneeIndex)-A2*D_beta;

            r1 = distr(gen);
            r2 = distr(gen);

            double A3=2.0*a*r1-a;
            double C3=2.0*r2;

            double D_delta= std::abs(C3*_population[_delta_index]->position(coordoneeIndex)-_population[solutionIndex]->position(coordoneeIndex));
            double X3 = _population[_delta_index]->position(coordoneeIndex)-A3*D_delta;

            double resultat=(X1+X2+X3)/3.0;
            _population[solutionIndex]->position(coordoneeIndex,resultat); //applique le resultat a la coordonnée courante de la solution courante
        }
    }
}


void optimizationAlgorithm::initialize()
{
    for (unsigned int i=0; i<_population.size(); i++)
    {
        _population[i]->initialize();
    }

}

void optimizationAlgorithm::evaluate()
{
    for(unsigned int iteration=0; iteration<_setup.nb_evolution_steps(); iteration++) //_setup-> ? car &
    {
        _fitness_values=fitness_values();

        evolution(iteration);

        _best_fitness_over_time[iteration]=_alpha_score;    //On garde le meilleur score de cette itération
        if(_alpha_score<best_cost()) //Si le score de cette itération est inférieur au meilleur score jamais trouvé
        {
            _best_solution=*_population[_alpha_index];
        }
    }
}

vector<double>&  optimizationAlgorithm::fitness_values()
{

    //calcule la fonction objectif de chaque solutions
    for(unsigned int i=0; i<_population.size(); i++)
    {
        _fitness_values[i]=_population[i]->fitness(_population[i]->pbm().get_numfunction());


        //Met a jour Alpha, Beta et Delta
        if(_fitness_values[i] < _alpha_score)
        {
            _alpha_score=_fitness_values[i];    //Mise a jour du score d'Alpha
            _alpha_index=i;                     //Mise a jour de la position d'Alpha
        }
        else if((_fitness_values[i] > _alpha_score) && (_fitness_values[i]<_beta_score))
        {
            _beta_score=_fitness_values[i];    //Mise a jour du score de Beta
            _beta_index=i;                    //Mise a jour de la position de Beta
        }
        else if((_fitness_values[i] > _alpha_score) && (_fitness_values[i]>_beta_score) && (_fitness_values[i]<_delta_score))
        {
            _delta_score=_fitness_values[i];    //Mise a jour du score de Delta
            _delta_index=i;                    //Mise a jour de la position de Delta
        }
    }

    return _fitness_values;
}


const vector<Solution*>& optimizationAlgorithm::solutions() const
{
    return _population;
}

Solution& optimizationAlgorithm::solution(const unsigned int index) const
{
    return *_population[index];
}

double optimizationAlgorithm::fitness(const unsigned int index) const
{
    return _fitness_values[index];
}


