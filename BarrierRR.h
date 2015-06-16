#ifndef BARRIERRR_H
#define BARRIERRR_H

#include "ProcessRR.h"
#include "BrownianRR.h"

class BarrierRR :
	public ProcessRR
{
public:
	BarrierRR(int n, double T, double x0, double k, double r, double s, double barrier) :
		ProcessRR(n), BRR(n, T), T(T), k(k), x0(x0), r(r), s(s), barrier(barrier) {};
	virtual void operator () () = 0;
	virtual void affine();
	virtual void showInfo();

protected:
	double T, x0, k, r, s, barrier;
	double probFator1, probFator2, probFator3;
	BrownianRR BRR;
	class fun_zero : public std::unary_function < state, state > {
	public:
		fun_zero(){};
		state operator()(const state &x) {
			return state(x.first, 0);
		};
	} make_zero;
};

#endif
