#include <iostream>
#include <algorithm>

int bigmod(int base, int exponent, int MOD = 1e9 + 7){
    if(!exponent) return 1;
    long long ret = bigmod(base, exponent >> 1, MOD);
    ret = (ret * ret) % MOD;
    if(exponent & 1) ret = (ret * base) % MOD;
    return ret;
}

int modularInverse(int base, int MOD){
    if(std::__gcd(base, MOD) != 1){
        std::cout << "Modular Inverse does not exist!\n";
        return -1;
    }
    return bigmod(base, MOD - 2) % MOD;
}

int main(int argc, char const *argv[])
{
    int base, exp, mod; 
    std::cin >> base >> exp >> mod;
    std::cout << bigmod(base, exp, mod) << '\n';
    return 0;
}

