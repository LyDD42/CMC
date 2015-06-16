#ifndef BROWNIAN_H
#define BROWNIAN_H

#include "Process.h"
#include "Gaussian.h"

class Brownian :
	public Process < double >
{
public:
	Brownian(int n, double T = 1);
	result_type operator()();
	result_type affine();
	friend class Barrier;
	friend class BarrierStatic;
	friend class BarrierDynamic;
	friend class BarrierDynamicImportantSampling;
	friend class UICStatic;
	friend class UICDynamic;
	friend class UICDynamicImportantSampling;
	template <typename S>
	friend std::ostream& operator<<(std::ostream& o, const Process<S>& p);
protected:
	int n;
	double h, T;
	Gaussian G;
};


#endif
