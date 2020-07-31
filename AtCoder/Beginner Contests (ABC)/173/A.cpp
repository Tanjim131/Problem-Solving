#include <iostream>

int main(int argc, char const *argv[])
{
    int N;
    std::cin >> N;
    int required = N / 1000;
    if(N % 1000 != 0) ++required;
    int rem = required * 1000 - N;
    std::cout << rem << '\n';
    return 0;
}
