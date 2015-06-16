#include "Barrier.h"

void Barrier::showInfo() {
	std::cout
		<< "Mat:\t" << T << std::endl
		<< "Spot:\t" << x0 << std::endl
		<< "Strike:\t" << k << std::endl
		<< "IR:\t" << r << std::endl
		<< "Vol:\t" << s << std::endl;
}

void Barrier::affine() {
	probFator = 1;
	double left, right, p;
	iter precedent = value.begin(), current = ++value.begin();
	while (current != value.end()) {
		left = (*precedent).second;
		right = (*precedent).second;
		if (left == 0 || right == 0) {
			probFator = 0;
			return;
		}
		p = 1 - exp(-2 * (barrier - left) * (barrier - right) / (pow(s * left, 2) * B.h));
		//std::cout << "p:" <<  << std::endl;
		probFator *= p;
		precedent = current;
		current++;
	}
}
