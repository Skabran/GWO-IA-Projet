#ifndef OPTIMIZATIONALGORITHM_H
#define OPTIMIZATIONALGORITHM_H
#include "Solution.h"
#include "SetUpParams.h"
#include <vector>

using namespace std;
class optimizationAlgorithm
  {
	private:
		vector<Solution*> _population;     // individuals in population
		vector<double> _fitness_values;
		const SetUpParams& _setup;
		unsigned int _lower_cost; // lower and upper fitness of individuals in population

	public:
      optimizationAlgorithm(const Problem& pbm,const SetUpParams& setup);
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

  };
#endif // OPTIMIZATIONALGORITHM_H
