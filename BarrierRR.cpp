#include "BarrierRR.h"


void BarrierRR::showInfo() {
	std::cout
		<< "Mat:\t" << T << std::endl
		<< "Spot:\t" << x0 << std::endl
		<< "Strike:\t" << k << std::endl
		<< "IR:\t" << r << std::endl
		<< "Vol:\t" << s << std::endl;
}

void BarrierRR::affine() {
	probFator1 = 1;
	probFator2 = 1;
	probFator3 = 1;
	double left, right, p;
	iter precedent = process1.begin(), current = ++process1.begin();
	while (current != process1.end()) {
		left = (*precedent).second;
		right = (*precedent).second;
		if (left == 0 || right == 0) {
			probFator1 = 0;
			break;
		}
		p = 1 - exp(-2 * (barrier - left) * (barrier - right) / (pow(s * left, 2) * BRR.h1));
		//std::cout << "p:" <<  << std::endl;
		probFator1 *= p;
		precedent = current;
		current++;
	}

	precedent = process2.begin(); current = ++process2.begin();
	while (current != process2.end()) {
		left = (*precedent).second;
		right = (*precedent).second;
		if (left == 0 || right == 0) {
			probFator2 = 0;
			break;
		}
		p = 1 - exp(-2 * (barrier - left) * (barrier - right) / (pow(s * left, 2) * BRR.h2));
		//std::cout << "p:" <<  << std::endl;
		probFator2 *= p;
		precedent = current;
		current++;
	}

	precedent = process3.begin(); current = ++process3.begin();
	while (current != process3.end()) {
		left = (*precedent).second;
		right = (*precedent).second;
		if (left == 0 || right == 0) {
			probFator2 = 0;
			break;
		}
		p = 1 - exp(-2 * (barrier - left) * (barrier - right) / (pow(s * left, 2) * BRR.h3));
		//std::cout << "p:" <<  << std::endl;
		probFator3 *= p;
		precedent = current;
		current++;
	}

}
