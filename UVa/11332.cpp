#include <iostream>

int main(int argc, char const *argv[])
{
    int n;
    while(std::cin >> n && n){
        int mod = n % 9;
        if(!mod) mod = 9;
        std::cout << mod << '\n';
    }
    return 0;
}
