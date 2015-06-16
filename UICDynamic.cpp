#include "UICDynamic.h"

UICDynamic::UICDynamic(int n, double T, double x0, double k, double r, double s, double u0, double alpha)
	: Barrier(n, T, x0, k, r, s, 1), u0(u0), alpha(alpha), dy(x0, r, s, u0, alpha) {}


UICDynamic::result_type UICDynamic::operator()() {
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

double UICDynamic::price() {
	return exp(-r * T) * std::max(value.back().second * (u0 + alpha * T) - k, 0.0) * (1 - probFator);
}

void UICDynamic::showInfo() {
	std::cout
		<< "UIC Option with dynamic barrier condition:" << std::endl;
	(*this).Barrier::showInfo();
	std::cout
		<< "u0:\t" << u0 << std::endl
		<< "alpha:\t" << alpha << std::endl;
}
