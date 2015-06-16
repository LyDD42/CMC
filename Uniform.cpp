#include "Uniform.h"



Uniform::Uniform(double left, double right)
	: left(left), right(right), dis(left, right)
{
	std::random_device rd;
	gen.seed(rd());
}

double Uniform::operator()() {
	return dis(gen);
}
