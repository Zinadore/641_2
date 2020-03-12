#include "Solver.h"
#include "cstdlib"

bool isprime(mpz_class n) {
    if (n == 2) { return true; }
    if (n == 3) { return true; }
    if (n % 2 == 0) { return false; }
    if (n % 3 == 0) { return false; }

    mpz_class i = 5;
    mpz_class w = 2;

    while (i * i <= n) {
        if (n % i == 0) { printf("IS NOT THE FATHER\n"); return false; }
        i += w;
        w = 6 - w;
    }
    printf("IS THE FATHER\n");
    return true;

}

mpz_class abso(mpz_class a)     //fn to return absolute value
{
    return a > 0 ? a : -a;
}
int recur_depth = 0;

mpz_class gcd(mpz_class a, mpz_class b)    //Euclidean GCD recursive fn
{
    if (b == 0)
        return a;
    else {
        //recur_depth++;
        return gcd(b, a % b);
    }
}

mpz_class pollard_rho(mpz_class& n)  //pollard rho implementation
{
    if (n % 2 == 0)
        return 2;

    mpz_class x = rand() % n + 1;
    mpz_class c = rand() % n + 1;
    mpz_class y = x;
    mpz_class g = 1;
    //printf("POLLARD RHO\n");
    //printf("INITIAL: x: %d | y: %d | c: %d | g: %d\n", x,y,c,g);
    
    int iteration = 0;
    while (g == 1) {
        x = ((x * x) % n + c) % n;
        y = ((y * y) % n + c) % n;
        y = ((y * y) % n + c) % n;
        //printf("x: %d | y: %d | c: %d | g %d\n", x,y,c,g);

        g = gcd(abso(x - y), n);
        //gmp_printf("Recurrence depth %d, g %Zd iteration %d\n", recur_depth, g, iteration);
        //recur_depth = 0;
        //iteration ++;
        //printf("GCD of %d and %d = %d\n", abso(x-y), n, g);
        //printf("\n");
    }
    return g;
}

TDivResult Solver::solve(mpz_class& n)
{
    TDivResult result;
    result.n = n;
    result.p = pollard_rho(n);
    result.q = n / result.p;


    return result;
}