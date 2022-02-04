pollard_rho.dll : pollard_rho.o
	g++ pollard_rho.o -o pollard_rho.dll -shared

pollard_rho.o : pollard_rho.cpp
	g++ pollard_rho.cpp -o pollard_rho.o -c -std=c++17

clean: 
	rm -f pollard_rho.o pollard_rho.dll