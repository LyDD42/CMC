#ifndef PROCESS_H
#define PROCESS_H

#include<iostream>
#include<list>
#include<utility>

template <typename T>
class Process
{
public:
	typedef std::pair<double, T> state;
	typedef std::list<state> result_type;
	typedef typename result_type::iterator iter;
	typedef typename result_type::const_iterator cst_iter;
	Process(int size);
	virtual result_type operator()() = 0;
	virtual ~Process();
	result_type current() const { return value; }
	template <typename S>
	friend std::ostream& operator<<(std::ostream& o, const Process<S>& p);

//protected:
	result_type value;
};

template <typename T>
Process<T>::Process(int size) : value(size)
{
}

template <typename T>
Process<T>::~Process()
{
}

template <typename T>
std::ostream& operator<<(std::ostream& o, const Process<T>& p)
{
	typename Process<T>::cst_iter i;
	for (i = p.value.begin(); i != p.value.end(); ++i)
		o << (*i).first << "\t" << (*i).second << std::endl;
	return o;
}

#endif
