#ifndef OPTIMIZATIONALGORITHM_H
#define OPTIMIZATIONALGORITHM_H
#include "Solution.h"
#include "SetUpParams.h"
#include <vector>

using namespace std;
class optimizationAlgorithm
  {
      public:
      optimizationAlgorithm(const Problem& pbm,const SetUpParams& setup); //setup avec un Probleme et un SetUpParam

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


		double best_cost() const; //Meilleur ever
		Solution& best_solution() const;

		void evolution(int iter); /*makes an evolution step*/

	private:
		vector<Solution*> _population;     // individuals in population
		vector<double> _fitness_values;    //la fitness de chaque individu (Solution)
		const SetUpParams& _setup;
		unsigned int _lower_cost; // lower fitness of individuals in population

        unsigned int _alpha_index;  //Meilleur de cette génération
        double _alpha_score;
        unsigned int _beta_index;
        double _beta_score;
        unsigned int _delta_index;
        double _delta_score;


  };
#endif // OPTIMIZATIONALGORITHM_H
