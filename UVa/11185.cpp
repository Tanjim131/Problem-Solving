#include <iostream>

void ternary(int n){
    if(!n) return;
    ternary(n / 3);
    std::cout << n % 3;
}

int main(int argc, char const *argv[])
{
    int n;
    while(std::cin >> n && n >= 0){
        if(n) ternary(n);
        else std::cout << '0';
        std::cout << '\n';
    }
    return 0;
}
