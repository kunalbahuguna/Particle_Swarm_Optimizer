## Particle Swarm Optimizer Code

### Methods
The following Particle Swarm Optimization (PSO) methods are implemented:

1. **Inertial Weight Method**: Implemented as described in the first PSO [paper](https://doi.org/10.1109/ICNN.1995.488968).
2. **Constriction Factor Method**: Prevents swarm "explosion." Refer to this [article](https://doi.org/10.1109/4235.985692).
3. **Fitness Distance Ratio-based PSO**: Uses neighboring best particles and improves global search. Details can be found in [this](https://doi.org/10.1007/3-540-45105-6_10) paper.

Inequality `g(x) <= 0` and equality `h(x) = 0` constraints are handled using a penalty function defined as:
$$H_i=pf*k^\alpha \theta(g_i(x)) g_i(x)^{\gamma}$$
where:
- `k` is the current iteration number,
- `alpha` is its power,
- `pf` is a constant penalty factor,
- `theta` is a dynamic weight,
- `gamma` is the power of violation.

The parameters `pf` and `alpha` are problem-dependent and can be adjusted in the `config.txt` file.

### Configuration
Define the following parameters in the `config.txt` file:

- **Population of Swarm**
- **Problem Number**
- **PSO Methods**:
    - `-w` for Inertial Weight Method
    - `-c` for Constriction Factor Method
    - `-f` for Fitness Distance Ratio-based PSO
- **Max number of iterations for optimizer**
- **Number of runs to perform**
- **Dimensions of Problem** (only used for N-dimensional problems)
- **Constants**:
    - Constraint Violation Tolerance
    - Penalty Factor
    - Alpha (Iteration Dependent Weight)

### Problems Defined
1. Spherical Function (N Dimensions)
2. Rastrigin Function (N Dimensions)
3. Rosenbrock Function (N Dimensions)
4. Ackley Function
5. Goldstein-Price Function
6. Beale Function
7. Booth Function
8. Matyas Function
9. Himmelblau's Multi-Modal Function
10. Constrained Rosenbrock Function
11. Colville Function No. 4
12. Colville Function No. 6
13. Himmelblau No. 1
14. Himmelblau No. 3
15. Himmelblau No. 5
16. Himmelblau No. 16
17. Himmelblau No. 17
18. Himmelblau No. 21
19. Himmelblau No. 24
20. Beale’s Problem 2
21. Rosen-Suzuki Problem
22. Cattle Feed Problem
23. Transformer Design Problem
Optimim and optimum position are written in opti_values.txt file.
More details can be found in the [wiki page](https://en.wikipedia.org/wiki/Test_functions_for_optimization) on test problems for optimization and the book [Test Examples for Nonlinear Programming Codes](https://link.springer.com/book/10.1007/978-3-642-48320-2) by Willi Hock and Klaus Schittkowski.

### How to Add a Problem
1. Add a function in `test_cases.cpp`:
   ```cpp
   vector<double> example_problem(vector<double> X)
   This function receives the position vector X and returns a vector with the objective function value, inequality constraints, and equality constraints (in this order).
2. Add the initialization in the initialize.cpp file for the problem by defining the dimensions (D), number of equality constraints (N_ec), and number of inequality constraints (N_iec).
3. Define the function pointer as:
   ```cpp
   tc_func = example_problem;
4. Lastly, add the function definition in the .h file.
