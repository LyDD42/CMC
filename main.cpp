// Monte Carlo Project.cpp : Defines the entry point for the console application.
//

#include "UOCStatic.h"
#include "UICStatic.h"
#include "UICDynamic.h"
#include "UICDynamicImportantSampling.h"
#include "UICDynamicISRR.h"
#include <iostream>
#include <limits>
#include <math.h>
#include <ctime>

int main()
{
	/*
	The parameters of option and the MC simulation can be chosen here before compiling
	X0: initial stock price
	K: strike
	r: interest rate
	s: annualized volatility
	T: maturity
	D: the constant barrier or the intercept of the linearly time dependent barrier function, u0 in the report
	mu: new drift of the process in importance sampling method, chosen as 1*s/sqrt(T)+r by default
	NSIM: Monte Carlo simulation numbers
	NSTEP: pow(2,NSTEP) is the discretization intervals for all methods except for Richardson-Romberg method
	NRR: the discretization intervals for RR method
	*/

	/* If user wants to show only some of the option prices, it suffices to comment part of the code.
	Each part begins with a comment specifing the option/method, and ends with "std::cout << "std:\t " << std_p / sqrt(NSIM) << std::endl;"
	*/
	const int NSIM = 100000;
	const int NSTEP = 5;
	const double X0 = 100, K = 100, r = 0.15, s = 1, T = 3, D = 300, alpha = 100;
	const double mu = 1*s/sqrt(T)+r;
	const int NRR = 16;
	long double priceCum = 0;
	long double price_sq_cum = 0;
	long double mean = 0;
	long double std_p = 0;
	std::clock_t start = std::clock();
	double duration;
	start = std::clock();

	// calculate the BS price as a reference
	UOCStatic bs = UOCStatic(NSTEP, T, X0, K, r, s, std::numeric_limits<double>::infinity());
	bs.showInfo();
	priceCum = 0;
	price_sq_cum = 0;
	for (int i = 0; i <= NSIM; i++) {
		bs();
		priceCum += bs.price();
		price_sq_cum += pow(bs.price(), 2);
	}
	mean = priceCum / NSIM;
	std_p = sqrt(price_sq_cum / NSIM - pow(mean, 2));
	std::cout << "price:\t" << mean << std::endl;
	std::cout << "std:\t " << std_p / sqrt(NSIM) << std::endl;

	// UOC with static condtion
	UOCStatic uocS = UOCStatic(NSTEP, T, X0, K, r, s, D);
	uocS.showInfo();
	priceCum = 0;
	price_sq_cum = 0;
	for (int i = 1; i <= NSIM; i++) {
		uocS();
		priceCum += uocS.price();
		price_sq_cum += pow(uocS.price(), 2);
	}
	mean = priceCum / NSIM;
	std_p = sqrt(price_sq_cum / NSIM - pow(mean, 2));
	std::cout << "price:\t" << mean << std::endl;
	std::cout << "std:\t " << std_p / sqrt(NSIM) << std::endl;

	 //UIC with static condition
	UICStatic uicS = UICStatic(NSTEP, T, X0, K, r, s, D);
	uicS.showInfo();
	priceCum = 0;
	price_sq_cum = 0;
	for (int i = 0; i <= NSIM; i++) {
		uicS();
		priceCum += uicS.price();
		price_sq_cum += pow(uicS.price(), 2);
	}
	mean = priceCum / NSIM;
	std_p = sqrt(price_sq_cum / NSIM - pow(mean, 2));
	std::cout << "price:\t" << mean << std::endl;
	std::cout << "std:\t " << std_p / sqrt(NSIM) << std::endl;

	// UIC with dynamic condition
	UICDynamic uicD = UICDynamic(NSTEP, T, X0, K, r, s, D, alpha);
	uicD.showInfo();
	priceCum = 0;
	price_sq_cum = 0;
	for (int i = 0; i <= NSIM; i++) {
		uicD();
		priceCum += uicD.price();
		price_sq_cum += pow(uicD.price(), 2);
	}
	mean = priceCum / NSIM;
	std_p = sqrt(price_sq_cum / NSIM - pow(mean, 2));
	std::cout << "price:\t" << mean << std::endl;
	std::cout << "std:\t " << std_p / sqrt(NSIM) << std::endl;

	// UIC with dynamic condition and Important Sampling method
	UICDynamicImportantSampling uicDIS = UICDynamicImportantSampling(NSTEP, T, X0, K, r, s, D, alpha, mu);
	uicDIS.showInfo();
	priceCum = 0;
	price_sq_cum = 0;
	for (int i = 0; i <= NSIM; i++) {
		uicDIS();
		priceCum += uicDIS.price();
		price_sq_cum += pow(uicDIS.price(), 2);
	}
	mean = priceCum / NSIM;
	std_p = sqrt(price_sq_cum / NSIM - pow(mean, 2));
	std::cout << "price:\t" << mean << std::endl;
	std::cout << "std:\t " << std_p / sqrt(NSIM) << std::endl;

	// UIC with dynamic condition and Important Sampling method and RR method
	UICDynamicISRR uicDISRR = UICDynamicISRR(NRR, T, X0, K, r, s, D, alpha, mu);
	uicDISRR.showInfo();
	priceCum = 0;
	price_sq_cum = 0;
	for (int i = 0; i <= NSIM; i++) {
		uicDISRR();
		priceCum += uicDISRR.price();
		price_sq_cum += pow(uicDISRR.price(), 2);
	}
	mean = priceCum / NSIM;
	std_p = sqrt(price_sq_cum / NSIM - pow(mean, 2));
	std::cout << "price:\t" << mean << std::endl;
	std::cout << "std:\t " << std_p / sqrt(NSIM) << std::endl;

	duration = (std::clock() - start) / (double)CLOCKS_PER_SEC;
	std::cout << "total time used: " << duration << '\n'; 
	
	return 0;
}
