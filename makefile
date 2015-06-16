CC=g++
CFlags=-c -std=c++11

all: MC clean

MC:	main.o UOCStatic.o UICStatic.o UICDynamic.o UICDynamicImportantSampling.o UICDynamicISRR.o Barrier.o Brownian.o Gaussian.o Uniform.o ProcessRR.o BarrierRR.o BrownianRR.o
	$(CC) -o MC main.o UOCStatic.o UICStatic.o UICDynamic.o UICDynamicImportantSampling.o UICDynamicISRR.o Barrier.o Brownian.o Gaussian.o Uniform.o ProcessRR.o BarrierRR.o BrownianRR.o
main.o: main.cpp UOCStatic.h UICStatic.h UICDynamic.h UICDynamicImportantSampling.h UICDynamicISRR.h
	$(CC) $(CFlags) main.cpp

UOCStatic.o: UOCStatic.cpp Barrier.h Brownian.h
	$(CC) $(CFlags) UOCStatic.cpp

UICStatic.o: UICStatic.cpp Barrier.h Brownian.h
	$(CC) $(CFlags) UICStatic.cpp

UICDynamic.o: UICDynamic.cpp Barrier.h Brownian.h
	$(CC) $(CFlags) UICDynamic.cpp

UICDynamicImportantSampling.o: UICDynamicImportantSampling.cpp Barrier.h Brownian.h
	$(CC) $(CFlags) UICDynamicImportantSampling.cpp

UICDynamicISRR.o: UICDynamicISRR.cpp BarrierRR.h BrownianRR.h
	$(CC) $(CFlags) UICDynamicISRR.cpp

Barrier.o: Barrier.cpp Process.h Brownian.h
	$(CC) $(CFlags) Barrier.cpp

Brownian.o: Brownian.cpp Process.h Gaussian.h
	$(CC) $(CFlags) Brownian.cpp

Gaussian.o: Gaussian.cpp RandomVariable.h Uniform.h
	$(CC) $(CFlags) Gaussian.cpp

Uniform.o: Uniform.cpp RandomVariable.h
	$(CC) $(CFlags) Uniform.cpp

ProcessRR.o: ProcessRR.cpp
	$(CC) $(CFlags) ProcessRR.cpp

BarrierRR.o: BarrierRR.cpp ProcessRR.h BrownianRR.h
	$(CC) $(CFlags) BarrierRR.cpp

BrownianRR.o: BrownianRR.cpp ProcessRR.h Gaussian.h
	$(CC) $(CFlags) BrownianRR.cpp
	

clean:
	rm *.o
