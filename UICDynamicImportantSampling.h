#ifndef UICDYNAMICIMPORTANTSAMPLING_H
#define UICDYNAMICIMPORTANTSAMPLING_H

#include "Barrier.h"
class UICDynamicImportantSampling :
	public Barrier
{
public:
	UICDynamicImportantSampling(int n, double T, double x0, double k, double r, double s, double u0, double alpha, double mu);
	virtual result_type operator() ();
	virtual double price();
	void showInfo();
protected:
	double u0, alpha;
	class dynamics : public std::unary_function<Barrier::state, Barrier::state> {
	public:
		dynamics(double x0, double r, double s, double u0, double alpha, double mu)
			: x0(x0), r(r), s(s), u0(u0), alpha(alpha), mu( mu ), lambda((r - mu) / s) {};
		state operator() (const state& x){
			return state(x.first, (x0 / u0) * exp((mu - 0.5 * s * s)*x.first - log((u0 + alpha * x.first) / u0) + s*x.second) );
		};
		friend class UICDynamicImportantSampling;
	private:
		double x0, r, s, u0, alpha, mu, lambda;
	} dy;
};

#endif
