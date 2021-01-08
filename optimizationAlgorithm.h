#ifndef OPTIMIZATIONALGORITHM_H
#define OPTIMIZATIONALGORITHM_H
#include "Solution.h"
#include "SetUpParams.h"
#include <vector>

using namespace std;
class optimizationAlgorithm
  {
      public:
        optimizationAlgorithm(Problem& pbm,const SetUpParams& setup); //setup avec un Probleme et un SetUpParam
        ~optimizationAlgorithm();
        void lanceEtAffiche();
		const SetUpParams& setup() const;
	  	void initialize();
        void evaluate(); // creates a array with fitness of all solutions in MyAlgorithm and its position in the MyAlgorithm
	 	const vector<Solution*>& solutions() const;
		Solution& solution(const unsigned int index) const;
        vector<double>&  fitness_values();
		double fitness(const unsigned int index) const;
		double best_cost() const; //Meilleure score depuis le debut
		Solution& best_solution() const; //Meilleure solution depuis le début
		void evolution(int iter); /*makes an evolution step*/

	private:
		vector<Solution*> _population;     // individuals in population
		vector<double> _fitness_values;    //la fitness de chaque individu (Solution)
		vector<double> _best_fitness_over_time; //Tableau gardant la meilleur fitness a chaque iteration
		Solution _best_solution; //Meilleure solution trouvée sur l'ensemble des itérations
		double _best_cost;
		const SetUpParams& _setup;

        unsigned int _alpha_index;         // Meilleur de cette génération
        double _alpha_score;               // lower fitness of individuals in population
        unsigned int _beta_index;
        double _beta_score;
        unsigned int _delta_index;
        double _delta_score;


  };
#endif // OPTIMIZATIONALGORITHM_H
