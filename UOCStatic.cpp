#include "UOCStatic.h"

UOCStatic::UOCStatic(int n, double T, double x0, double k, double r, double s,
	double barrier)
	: Barrier(n, T, x0, k, r, s, barrier), dy(x0, r, s) {}


UOCStatic::result_type UOCStatic::operator()() {
	B();
	std::transform(B.value.begin(), B.value.end(), value.begin(), dy);
	for (iter i = value.begin(); i != value.end(); ++i){
		if ((*i).second >= barrier){
			std::transform(i, value.end(), i, make_zero);
			return value;
		}
	}
	affine();
	return value;
}

double UOCStatic::price() {
	return exp(-r * T) * std::max(value.back().second - k, 0.0) * probFator;
}

void UOCStatic::showInfo() {
	(*this).Barrier::showInfo();
	std::cout
		<< "Max:\t" << barrier << std::endl;
}
