#include <iostream>
#include <algorithm>
#include <tuple>

// performs correct results for negative integers as well (why?)
// O(log(max(a,b))^2) - two pass (number of division steps)

int extended_euclid_recursive(int a, int b, int &x, int &y){
    if(!b){
        x = 1;
        y = 0;
        return a;
    }
    int x1,y1;
    int g = extended_euclid_recursive(b, a % b, x1, y1);
    x = y1;
    y = x1 - y1 * (a / b);
    return g;
}

// To see why the algorithm also computes the correct coefficients, 
// you can check that the following invariants will hold at any time 
// (before the while loop, and at the end of each iteration): ax + by = a1 and ax1 + by1 = b1. 
// It's trivial to see, that these two equations are satisfied at the beginning. 
// And you can check that the update in the loop iteration will still keep those equalities valid.
// At the end we know that a1 contains the GCD, so ax + by = g. Which means that we have found the required coefficients.
// You can even optimize the code more, and remove the variable a1 and b1 from the code, and just reuse a and b. 
// However if you do so, you loose the ability to argue about the invariants.

// O(log(max(a,b))) - one pass

int extended_euclid_iterative(int a, int b, int &x, int &y){
    x = 1, y = 0;
    int x1 = 0, y1 = 1, a1 = a, b1 = b;
    while (b1) {
        int q = a1 / b1;
        std::tie(x, x1) = std::make_tuple(x1, x - q * x1);
        std::tie(y, y1) = std::make_tuple(y1, y - q * y1);
        std::tie(a1, b1) = std::make_tuple(b1, a1 - q * b1);
    }
    // (x,y) - bezout's co-efficients
    // (x1,y1) - quotients when gcd divides a and b respectively (absolute value)
    return a1;
}

int main(int argc, char const *argv[])
{
    int a,b,x,y;
    std::cin >> a >> b;
    //int g = extended_euclid_recursive(a,b,x,y);
    int g = extended_euclid_iterative(a,b,x,y);
    std::cout << "GCD of (" << a << "," << b << ") is " << g << '\n';
    std::cout << a << " * " << x << " + " << b << " * " << y << " = " << g << '\n'; 
    return 0;
}
