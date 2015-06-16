#include "UICDynamicISRR.h"


UICDynamicISRR::UICDynamicISRR(int n, double T, double x0, double k, double r, double s, double u0, double alpha, double mu)
	: BarrierRR(n, T, x0, k, r, s, 1), u0(u0), alpha(alpha), dy(x0, r, s, u0, alpha, mu) {};

void UICDynamicISRR::operator()() {
	BRR();
	std::transform(BRR.process1.begin(), BRR.process1.end(), process1.begin(), dy);
	std::transform(BRR.process2.begin(), BRR.process2.end(), process2.begin(), dy);
	std::transform(BRR.process3.begin(), BRR.process3.end(), process3.begin(), dy);
	for (iter i = process1.begin(); i != process1.end(); ++i){
		if ((*i).second >= 1){
			probFator1 = 0;
			break;
		}
	}
	for (iter i = process2.begin(); i != process2.end(); ++i){
		if ((*i).second >= 1){
			probFator2 = 0;
			break;
		}
	}
	for (iter i = process3.begin(); i != process3.end(); ++i){
		if ((*i).second >= 1){
			probFator3 = 0;
			break;
		}
	}
	affine();
	return;
}


double UICDynamicISRR::price() {
	double p1 = exp(-r * T) * std::max(process1.back().second * (dy.u0 + dy.alpha * T) - k, 0.0) * exp(-0.5 * dy.lambda * dy.lambda * T + dy.lambda * BRR.process1.back().second) * (1 - probFator1);
	double p2 = exp(-r * T) * std::max(process2.back().second * (dy.u0 + dy.alpha * T) - k, 0.0) * exp(-0.5 * dy.lambda * dy.lambda * T + dy.lambda * BRR.process2.back().second) * (1 - probFator2);
	double p3 = exp(-r * T) * std::max(process3.back().second * (dy.u0 + dy.alpha * T) - k, 0.0) * exp(-0.5 * dy.lambda * dy.lambda * T + dy.lambda * BRR.process3.back().second) * (1 - probFator3);
	double alpha1 = (sqrt(3) - sqrt(2)) / (2 * sqrt(2) - sqrt(3) - 1);
	double alpha2 = (2 - 2 * sqrt(3))	/ (2 * sqrt(2) - sqrt(3) - 1);
	double alpha3 = (3 * sqrt(2) - 3)	/ (2 * sqrt(2) - sqrt(3) - 1);
	return alpha1 *p1 + alpha2 * p2 + alpha3 * p3;

}

void UICDynamicISRR::showInfo() {
	std::cout << "UIC Option with dynamic barrier condition, Important Sampling Method and RR Extrapolation:" << std::endl;
	(*this).BarrierRR::showInfo();
	std::cout << "u0:\t" << u0 << std::endl
		<< "alpha:\t" << alpha << std::endl
		<< "mu:\t" << dy.mu << std::endl
		<< "lambda:\t" << dy.lambda << std::endl;
}
