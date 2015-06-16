#include "UICStatic.h"

UICStatic::UICStatic(int n, double T, double x0, double k, double r, double s, double barrier)
	: Barrier(n, T, x0, k, r, s, barrier), dy(x0, r, s) {}


UICStatic::result_type UICStatic::operator()() {
	B();
	std::transform(B.value.begin(), B.value.end(), value.begin(), dy);
	for (iter i = value.begin(); i != value.end(); ++i){
		if ((*i).second >= barrier){
			probFator = 0;
			return value;
		}
	}
	affine();
	return value;
}


double UICStatic::price() {
	return exp(-r * T) * std::max(value.back().second - k, 0.0) * (1 - probFator);
}

void UICStatic::showInfo() {
	std::cout
		<< "UIC Option with static barrier condition:" << std::endl;
	(*this).Barrier::showInfo();
	std::cout
		<< "barrier:" << barrier << std::endl;
}
