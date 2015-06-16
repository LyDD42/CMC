#ifndef UICDYNAMICISRR_H
#define UICDYNAMICISRR_H

#include "BarrierRR.h"
#include <algorithm>

class UICDynamicISRR :
	public BarrierRR
{
public:
	UICDynamicISRR(int n, double T, double x0, double k, double r, double s, double u0, double alpha, double mu);
	void operator() ();
	double price();
	void showInfo();
	friend std::ostream& operator<<(std::ostream& o, const ProcessRR& p);
protected:
	double u0, alpha;
	class dynamics : public std::unary_function<BarrierRR::state, BarrierRR::state> {
	public:
		dynamics(double x0, double r, double s, double u0, double alpha, double mu)
			: x0(x0), r(r), s(s), u0(u0), alpha(alpha), mu( mu ), lambda((r - mu) / s) {};
		state operator() (const state& x){
			return state(x.first, (x0 / u0) * exp((mu - 0.5 * s * s)*x.first - log((u0 + alpha * x.first) / u0) + s*x.second));
		};
		friend class UICDynamicISRR;
	private:
		double x0, r, s, u0, alpha, mu, lambda;
	} dy;
};

#endif
