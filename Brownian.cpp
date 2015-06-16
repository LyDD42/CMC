#include "Brownian.h"


Brownian::Brownian(int n, double T)
	: Process<double>(pow(2, n) + 1), n(n), T(T),
	h(T / pow(2., n)), G(0, sqrt(h)) {}

Brownian::result_type Brownian::operator()(){
	value.clear();
	state val_k(0, 0);
	value.push_back(val_k);
	do {
		val_k.first += h;
		val_k.second += G();
		value.push_back(val_k);
	} while (val_k.first < T);
	return value;
}

Brownian::result_type Brownian::affine(){
	n++; h *= 0.5;
	G = Gaussian(0, sqrt(0.5*h));
	iter precedent = value.begin(), current = ++value.begin();
	while (current != value.end()) {
		value.insert(current,
			state(0.5*((*current).first + (*precedent).first),
			0.5*((*current).second + (*precedent).second) + G()));
		precedent = current;
		current++;
	}
	return value;
}
