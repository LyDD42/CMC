#ifndef UICDYNAMIC_H
#define UICDYNAMIC_H

#include <algorithm>
#include "Barrier.h"
#include "Brownian.h"

class UICDynamic :
	public Barrier
{
public:
	UICDynamic(int n, double T, double x0, double k, double r, double s, double u0, double alpha);
	virtual result_type operator()();
	virtual double price();
	virtual void showInfo();
	template <typename S>
	friend std::ostream& operator<<(std::ostream& o, const Process<S>& p);


protected:
	double u0, alpha;
private:
	class dynamics : public std::unary_function < Barrier::state, Barrier::state >  {
	public:
		dynamics(double x0, double r, double s, double u0, double alpha)
			: x0(x0), r(r), s(s), u0(u0), alpha(alpha) {};
		state operator()(const state &x) {
			return state(x.first, (x0 / u0) * exp((r - 0.5 * s * s)*x.first - log((u0 + alpha * x.first) / u0) + s*x.second));
		};
	private:
		double x0, r, s, u0, alpha;
	} dy;

};

#endif
