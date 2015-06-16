#ifndef BROWNIANRR_H
#define BROWNIANRR_H

#include "ProcessRR.h"
#include "Gaussian.h"

class BrownianRR :
	public ProcessRR
{
public:
	BrownianRR(int n, double T);
	virtual void operator () ();
	friend class BarrierRR;
	friend class UICDynamicISRR;
	friend std::ostream& operator<<(std::ostream& o, const ProcessRR& p);
protected:
	double T;
	double h1, h2, h3;
	Gaussian G;
};

#endif
