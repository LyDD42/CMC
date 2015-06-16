========================================================================
    Monte Carlo Project Project Overview
========================================================================


/////////////////////////////////////////////////////////////////////////////

1. Compilation Instruction

	Run the command make will automatically generate an executable file MC in
	the current directory. It will compute the price for both UIC and UOC
	option by different methods for given parameters.

	You can manually change the parameters in main.cpp and choose the approp-
	riate method.

/////////////////////////////////////////////////////////////////////////////

2. File Description

main.cpp

	This file contains the main functions. It also specifies the parameters
	for target option.

RandomVariable.h

	This file defines a abstract class template called RandomVariable. It has a 
	pure virtual member method operator()() which should be overriden, and should
	generate a random number for a given type T.

Uniform.h Uniform.cpp

	This file defines Uniform class, which is an instance of RandomVariable<double> 
	class. Its operator()() generate a unifrom number on a given interval.

Gaussian.h Gaussian.cpp

	This file defines Uniform class, which is an instance of RandomVariable<double> 
	class. Its operator()() generate a unifrom number for given mean and std.

Process.h

	This file defines a abstract class template called Process.

	It defines a list which contains the time and value for a process.

	Its pure virtual member method operator()() should be realized to simulate this 
	process.

Brownian.h Brownina.cpp

	This file defines the Brownian class, which is an instance of Process<double>

Barrier.h Barrier.cpp

	This file define an abstract class called Barrier, which is an instance of
	Process<double>

	It has two pure virtual member methods: operator()() should run a simulation
	and update the state process, price() should return the price for one simulation.

UOCStatic.h UOCStatic.cpp UICStatic.h UICStatic.cpp UICDynamic.h UICDynamic.cpp
UICDynamicImportantSampling.h UICDynamicImportantSampling.cpp

	These files define different classes to simulate barrier option for different
	methods.
	
	All these classes are derived class of Barrier. 
	
	They use different private member class dynamics to override operator()().

	They override price() method to return the price for one simulation.

ProcessRR.h ProcessRR.cpp
	
	This file defines an abstract class ProcessRR aiming to realize Richardson-
	Romberg Extrapolation.

	It has three members representing three processes and its pure virtual
	member method should simulate them at the same time.

BrownianRR.h Brownian.cpp

	This is a derived class of ProcessRR.

UICDynamicISRR.h UICDynamicISRR.cpp

	This file define UICDynamicISRR class, which is used to realized Richardson-
	Romberg Extrapolation method.

	This class is a subclass of ProcessRR, and acts like other barrier option
	classes.


/////////////////////////////////////////////////////////////////////////////
