#ifndef RANDOMVARIABLE_H
#define RANDOMVARIABLE_H

template<typename T>
class RandomVariable
{
public:
	typedef T result_type;
	RandomVariable();
	RandomVariable(T value);
	virtual result_type operator()() = 0;
	virtual ~RandomVariable();
	result_type current() const { return value; };
protected:
	result_type value;
};



template <typename T>
RandomVariable<T>::RandomVariable() : value(0)
{
}

template <typename T>
RandomVariable<T>::RandomVariable(T value) : value(value)
{
}

template <typename T>
RandomVariable<T>::~RandomVariable()
{
}


#endif
