#ifndef PROBLEM_H
#define PROBLEM_H


class Problem
  {
	public:
		Problem(int dim, double lowerLimit, double upperLimit, int numfunction);
		~Problem();

		int dimension() const;
		int get_numfunction() const;
		int get_lowerLimit() const;
		int get_upperLimit() const;

	private:

		int _dimension;
		double _lowerLimit, _upperLimit;
		int _numfunction;

  };
#endif // PROBLEM_H
