#PSO MAKE FILE
CXX = g++
CXXFLAGS = -lm -std=c++11 -Wall
all: pso

pso: pso_main.o read_config.o opti_pso.o init_val.o calc_func.o gen_rand.o calc_fitness.o print_utils.o psoheader
	$(CXX) $(CXXFLAGS) pso_main.o read_config.o opti_pso.o init_val.o calc_func.o gen_rand.o calc_fitness.o print_utils.o psoheader.h -o pso.out
opti_pso.o: opti_pso.cpp psoheader
	$(CXX) $(CXXFLAGS) -c opti_pso.cpp
read_config.o: read_config.cpp psoheader
	$(CXX) $(CXXFLAGS) -c read_config.cpp
init_val.o: init_val.cpp psoheader
	$(CXX) $(CXXFLAGS) -c init_val.cpp
calc_func.o: calc_func.cpp psoheader
	$(CXX) $(CXXFLAGS) -c calc_func.cpp
gen_rand.o: gen_rand.cpp psoheader
	$(CXX) $(CXXFLAGS) -c gen_rand.cpp
pso_main.o: pso_main.cpp psoheader
	$(CXX) $(CXXFLAGS) -c pso_main.cpp
calc_fitness.o: calc_fitness.cpp psoheader
	$(CXX) $(CXXFLAGS) -c calc_fitness.cpp
print_utils.o: print_utils.cpp
	$(CXX) $(CXXFLAGS) -c print_utils.cpp
psoheader:
	$(CXX) $(CXXFLAGS) -c psoheader.h
clean: 
	$(RM) count *.o *~
