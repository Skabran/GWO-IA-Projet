#ifndef SOLUTION_H
#define SOLUTION_H
#include "Problem.h"


#include <vector>
using namespace std;

class Solution
  {
	public:
		Solution (const Problem& pbm);
		Solution (const Solution& sol);
		~Solution();

		const Problem& pbm() const;

		Solution& operator=  (const Solution& sol);
		bool operator== (const Solution& sol) const;
		bool operator!= (const Solution& sol) const;

		void initialize();
		double fitness(int numfunction);
		double get_fitness();

		vector<double>& solution();

		double& position(const int index);
        void  position(const int index, const double value);


	private:
        vector<double> _solution;   //coordonnées de chaques solution. Sa taille est le nb de dimensions
        double _current_fitness;
		const Problem& _pbm;
  };
#endif // SOLUTION_H
