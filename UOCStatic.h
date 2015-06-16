#ifndef UOCSTATIC_H
#define UOCSTATIC_H

#include <algorithm>
#include <limits>
#include "Barrier.h"
#include "Brownian.h"


class UOCStatic :
	public Barrier
{
public:
	UOCStatic(int n, double T, double x0, double k, double r, double s,
		double barrier = std::numeric_limits<double>::infinity());
	result_type operator()();
	double price();
	void showInfo();
	template <typename S>
	friend std::ostream& operator<<(std::ostream& o, const Process<S>& p);

private:
	class dynamics : public std::unary_function < UOCStatic::state, UOCStatic::state > {
	public:
		dynamics(double x0, double r, double s)
			: x0(x0), r(r), s(s) {};
		state operator()(const state &x) {
			return state(x.first, x0*exp((r - 0.5 * s * s) * x.first + s * x.second));
		};
	private:
		double x0, r, s;
	} dy;
};

#endif
