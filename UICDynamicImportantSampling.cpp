#include "UICDynamicImportantSampling.h"
#include <algorithm>


UICDynamicImportantSampling::UICDynamicImportantSampling(int n, double T, double x0, double k, double r, double s, double u0, double alpha, double mu)
	: Barrier(n, T, x0, k, r, s, 1), u0(u0), alpha(alpha), dy(x0, r, s, u0, alpha, mu) {};


UICDynamicImportantSampling::result_type UICDynamicImportantSampling::operator()() {
	B();
	std::transform(B.value.begin(), B.value.end(), value.begin(), dy);
	for (iter i = value.begin(); i != value.end(); ++i){
		if ((*i).second >= 1){
			probFator = 0;
			return value;
		}
	}
	affine();
	return value;
}


double UICDynamicImportantSampling::price() {
	return exp(-r * T) * std::max(value.back().second * (dy.u0 + dy.alpha * T) - k, 0.0) * exp(-0.5 * dy.lambda * dy.lambda * T + dy.lambda * B.value.back().second) * (1 - probFator);
}

void UICDynamicImportantSampling::showInfo() {
	std::cout << "UIC Option with dynamic barrier condition and Important Sampling Method:" << std::endl;
	(*this).Barrier::showInfo();
	std::cout << "u0:\t" << u0 << std::endl
		<< "alpha:\t" << alpha << std::endl
		<< "mu:\t" << dy.mu << std::endl
		<< "lambda:\t" << dy.lambda << std::endl;
}
