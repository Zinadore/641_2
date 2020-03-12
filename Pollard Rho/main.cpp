#include <iostream>
#include <chrono>
#include "Solver.h"
#include "mpirxx.h"

void print_usage(void) {
    std::cout << "Usage: rho n\n" << std::endl;
}

// Test Data
// n: 1440821087
// p : 31259
// q : 46093

int main(int argc, char** argv)
{
    if (argc != 2) {
        print_usage();
        exit(0);
    }

    mpz_class n(argv[1], 10);

    auto start = std::chrono::steady_clock::now();


    Solver* the_solver = new Solver();

    TDivResult result = the_solver->solve(n);

    auto end = std::chrono::steady_clock::now();

    std::cout << "n: " << result.n << std::endl;
    std::cout << "p: " << result.p << std::endl;
    std::cout << "q: " << result.q << std::endl;
    std::cout << "Elapsed time in milliseconds : "
        << std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count()
        << " ms" << std::endl;

    std::cout << "Elapsed time in seconds : "
        << std::chrono::duration_cast<std::chrono::seconds>(end - start).count()
        << " sec" << std::endl;

    std::cout << "Elapsed time in minutes : "
        << std::chrono::duration_cast<std::chrono::minutes>(end - start).count()
        << " mins" << std::endl;

    delete the_solver;
    return 0;
}