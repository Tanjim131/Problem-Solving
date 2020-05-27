#include <iostream>
#include <algorithm>
#include <iomanip>

bool is_relatively_prime(int a, int b){
    return std::__gcd(a,b) == 1;
}

int main(int argc, char const *argv[])
{
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
    int step, mod;
    while(std::cin >> step >> mod){
        std::cout << std::right << std::setw(10) << step;
        std::cout << std::right << std::setw(10) << mod;
        if(is_relatively_prime(step, mod)){
            std::cout << std::setw(16) << "Good Choice\n";
        } else{
            std::cout << std::setw(15) << "Bad Choice\n";
        }
        std::cout << '\n';
    }
    return 0;
}
