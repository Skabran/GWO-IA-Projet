#ifndef OPTIMIZATIONALGORITHM_H
#define OPTIMIZATIONALGORITHM_H
#include "Solution.h"
#include "SetUpParams.h"
#include <vector>

using namespace std;
class optimizationAlgorithm
  {
      public:
      optimizationAlgorithm(const Problem& pbm,const SetUpParams& setup); //setup avec un benchmark et un nombre d'agent (pas de nombre d'itération ?)
		~optimizationAlgorithm();

		const SetUpParams& setup() const;
	  	void initialize();

		// creates a array with fitness of all solutions in MyAlgorithm and its position in the MyAlgorithm
        void evaluate();

	 	const vector<Solution*>& solutions() const;
		unsigned int upper_cost() const;
		unsigned int lower_cost() const;
		Solution& solution(const unsigned int index) const;
        vector<double>&  fitness_values();
		double fitness(const unsigned int index) const;


		double best_cost() const;
		Solution& best_solution() const;

		void evolution(int iter); /*makes an evolution step*/

	private:
		vector<Solution*> _population;     // individuals in population
		vector<double> _fitness_values;    //la fitness de chaque individu (Solution)
		const SetUpParams& _setup;
		unsigned int _lower_cost; // lower and upper fitness of individuals in population
        unsigned int _upper_cost;


  };
#endif // OPTIMIZATIONALGORITHM_H
