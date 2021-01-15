#include "optimizationAlgorithm.h"
#include <iostream>
#include <fstream>
#include <cmath>
#include <vector>
#include "Problem.h"
#include "Solution.h"
#include <random>
#include <ctime>
#include <stdio.h>
#include <stdlib.h>
#include <climits>

using namespace std;

optimizationAlgorithm::optimizationAlgorithm(Problem& pbm, const SetUpParams& setup): _setup{setup}, _population{},
    _alpha_index{0}, _alpha_score{INT_MAX}, _beta_index{0}, _beta_score{INT_MAX}, _delta_index{0}, _delta_score{INT_MAX},
    _fitness_values{}, _best_fitness_over_time{}, _best_cost{INT_MAX},_best_solution{pbm}
{
    _fitness_values.resize(setup.population_size());
    _best_fitness_over_time.resize(setup.nb_evolution_steps());
    _population.resize(setup.population_size(),nullptr);
    for(int i=0; i<setup.population_size(); i++)
    {
        _population[i] = new Solution{pbm};
    }
    initialize();
}

optimizationAlgorithm::~optimizationAlgorithm()
{
    for(unsigned int i=0; i<_setup.population_size(); i++)
    {
        delete _population[i];
    }
}


void optimizationAlgorithm::lanceEtAffiche()
{
    for(unsigned int i=0; i<_setup.independent_runs(); i++)
    {
        evaluate();
        cout<<"la meilleure fitness est " << _best_cost << " sur le benchmark N� "<< _population[0]->pbm().get_numfunction()<< endl;
        initialize();
    }
}

void optimizationAlgorithm::evolution(int iter)
{
    default_random_engine gen{static_cast<long unsigned int>(time(0))};
    uniform_real_distribution<> distr(0,1);

    double a = 2.0 * iter*(2.0/_setup.nb_evolution_steps());

    Solution *solAlpha=new Solution{_population[0]->pbm()};
    *solAlpha=*_population[_alpha_index];

    Solution *solBeta=new Solution{_population[0]->pbm()};
    *solBeta=*_population[_beta_index];

    Solution *solDelta=new Solution{_population[0]->pbm()};
    *solDelta=*_population[_delta_index];

    for(unsigned int solutionIndex=0; solutionIndex<_population.size(); solutionIndex++)
    {
        for(unsigned int coordoneeIndex=0; coordoneeIndex<_population[solutionIndex]->solution().size(); coordoneeIndex++)
        {

            double r1 = distr(gen);
            double r2 = distr(gen);

            double A1=2.0*a*r1-a;
            double C1=2.0*r2;

            double D_alpha= abs((C1*solAlpha->position(coordoneeIndex))-_population[solutionIndex]->position(coordoneeIndex));
            double X1 = solAlpha->position(coordoneeIndex)-A1*D_alpha;

            r1 = distr(gen);
            r2 = distr(gen);

            double A2=2.0*a*r1-a;
            double C2=2.0*r2;

            double D_beta= abs(C2*solBeta->position(coordoneeIndex)-_population[solutionIndex]->position(coordoneeIndex));
            double X2 = solBeta->position(coordoneeIndex)-A2*D_beta;

            r1 = distr(gen);
            r2 = distr(gen);

            double A3=2.0*a*r1-a;
            double C3=2.0*r2;

            double D_delta= abs(C3*solDelta->position(coordoneeIndex)-_population[solutionIndex]->position(coordoneeIndex));
            double X3 = solDelta->position(coordoneeIndex)-A3*D_delta;

            double resultat=(X1+X2+X3)/3.0;
            _population[solutionIndex]->position(coordoneeIndex,resultat); //applique le resultat a la coordonn�e courante de la solution courante

        }
    }

    delete solAlpha;
    delete solBeta;
    delete solDelta;
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

    for(unsigned int iteration=0; iteration<_setup.nb_evolution_steps(); iteration++)
    {
        _fitness_values=fitness_values();

        evolution(iteration);

        _best_fitness_over_time[iteration]=_alpha_score;    //On garde le meilleur score de cette it�ration
        if(_alpha_score<best_cost()) //Si le score de cette it�ration est inf�rieur au meilleur score jamais trouv�
        {
            _best_cost=_alpha_score;
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
        if(abs(_fitness_values[i]) < _alpha_score)
        {
            _alpha_score=_fitness_values[i];    //Mise a jour du score d'Alpha
            _alpha_index=i;                     //Mise a jour de la position d'Alpha
        }
        else if((abs(_fitness_values[i]) > _alpha_score) && (abs(_fitness_values[i])<_beta_score))
        {
            _beta_score=_fitness_values[i];    //Mise a jour du score de Beta
            _beta_index=i;                    //Mise a jour de la position de Beta
        }
        else if((abs(_fitness_values[i]) > _alpha_score) && (abs(_fitness_values[i])>_beta_score) && (abs(_fitness_values[i])<_delta_score))
        {
            _delta_score=_fitness_values[i];    //Mise a jour du score de Delta
            _delta_index=i;                    //Mise a jour de la position de Delta
        }
    }

    return _fitness_values;
}


double optimizationAlgorithm::best_cost() const
{
    return _best_cost;
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


