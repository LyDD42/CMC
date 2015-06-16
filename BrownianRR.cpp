#include "BrownianRR.h"


BrownianRR::BrownianRR(int n, double T) :ProcessRR(n), T(T), h1(T / (n + 1)), h2(T / (2 * (n + 1))), h3(T / (3 * (n + 1)))
{
}

void BrownianRR::operator() () {
	int counter = 0;

	process1.clear();
	process2.clear();
	process3.clear();

	state val1(0, 0);
	state val2(0, 0);
	state val3(0, 0);
	process1.push_back(val1);
	process2.push_back(val2);
	process3.push_back(val3);
	do {
		double u1 = G();
		double u2 = G();
		double u3 = G();
		double u4 = G();
		val3.first += h3;
		val3.second += sqrt(h3) * u1;
		process3.push_back(val3);
		val3.first += h3;
		val3.second += sqrt(h3) * (u2 + u3) / sqrt(2);
		process3.push_back(val3);
		val3.first += h3;
		val3.second += sqrt(h3) * u4;
		process3.push_back(val3);

		val2.first += h2;
		val2.second += sqrt(h2) * (sqrt(2) * u1 + u2) / sqrt(3);
		process2.push_back(val2);
		val2.first += h2;
		val2.second += sqrt(h2) * (sqrt(2) * u4 + u3) / sqrt(3);
		process2.push_back(val2);

		val1.first += h1;
		val1.second += sqrt(h1) * (sqrt(2) * u1 + u2 + sqrt(2) * u4 + u3) / sqrt(6);
		process1.push_back(val1);

		counter++;
	} while (counter <= n);
}



