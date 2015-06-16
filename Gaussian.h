#ifndef GAUSSIAN_H
#define GAUSSIAN_H

#include "RandomVariable.h"
#include <math.h>
#include "Uniform.h"

class Gaussian :
	public RandomVariable < double >
{
public:
	Gaussian(double mean = 0, double std = 1)
			: mean(mean), std(std), flag(true), unif(-1, 1) {};
	double operator()();
private:
	double mean, std, U, V, R2, rac;
	Uniform unif;
	bool flag;
};

#endif
