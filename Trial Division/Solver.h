#pragma once
#include <mpirxx.h>

struct TDivResult {
    mpz_class n;
    mpz_class p;
    mpz_class q;
};


class Solver {

public:
    Solver() = default;
    ~Solver() = default;
    TDivResult solve(mpz_class& n);
};