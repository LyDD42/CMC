#ifndef UNIFORM_H
#define UNIFORM_H

#include "RandomVariable.h"
#include <random>

class Uniform :
	public RandomVariable < double >
{
public:
	Uniform(double left = 0, double right = 1);
	double operator ()();
private:
	double left, right;
	std::mt19937 gen;
	std::uniform_real_distribution<double> dis;
};

#endif
