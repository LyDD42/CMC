#include "Gaussian.h"


//double Gaussian::operator()(){
//	flag = !flag;
//	if (!flag) {
//		do {
//			U = unif(); V = unif();
//			R2 = U*U + V*V;
//		} while (R2 > 1);
//		rac = sqrt(-2 * log(R2) / R2);
//		return value = mean + std * U * rac;
//	}
//	else
//		return value = mean + std * V * rac;
//}

double Gaussian::operator()(){
	flag = !flag;
	if (!flag) {
		do {
			U = unif(); V = unif();
			R2 = U*U + V*V;
		} while (R2 > 1);
		rac = sqrt(-2 * log(R2) / R2);
		return value = mean + std * U * rac;
	}
	else
		return value = mean + std * V * rac;
}
