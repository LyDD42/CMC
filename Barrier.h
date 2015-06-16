#ifndef BARRIER_H
#define BARRIER_H

#include "Process.h"
#include "Brownian.h"


class Barrier :
	public Process < double >
{
public:
	Barrier(int n, double T, double x0, double k, double r, double s, double barrier)
		: Process<double>(pow(2, n) + 1), B(n, T), T(T), k(k), x0(x0), r(r), s(s), barrier(barrier) {};
	virtual result_type operator() () = 0;
	virtual void affine();
	virtual double price() = 0;
	virtual void showInfo();
protected:
	int n;
	double T, x0, k, r, s, barrier;
	double probFator;
	Brownian B;
	class fun_zero : public std::unary_function < state, state > {
	public:
		fun_zero(){};
		state operator()(const state &x) {
			return state(x.first, 0);
		};
	} make_zero;
};

#endif
