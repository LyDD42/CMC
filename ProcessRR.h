#ifndef PROCESSRR_H
#define	PROCESSRR_H

#include<iostream>
#include<list>
#include<utility>

class ProcessRR
{
public:
	typedef std::pair<double, double> state;
	typedef std::list<state> result_type;
	typedef result_type::iterator iter;
	typedef result_type::const_iterator cst_iter;
	ProcessRR(int n) : n(n), process1(n + 2), process2(2 * n + 3), process3(3 * n + 4) {};
	virtual void operator()() = 0;
	virtual ~ProcessRR() {};
	friend std::ostream& operator<<(std::ostream& o, const ProcessRR& p);

protected:
	result_type process1, process2, process3;
	int n;
};

#endif
