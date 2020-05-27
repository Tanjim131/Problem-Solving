#include <iostream>

int main(int argc, char const *argv[])
{
    unsigned int a,b;
    while(std::cin >> a >> b){
        std::cout << (a ^ b) << '\n';
    }
    return 0;
}
