#include <iostream>

int main(int argc, char const *argv[])
{
    long long n;
    std::cin >> n;
    long long sumOfSequence = 0;
    for(int i = 0 ; i < n - 1 ; ++i){
        int x; std::cin >> x;
        sumOfSequence += x;
    }   
    long long sumUpToN = n * (n + 1) / 2;
    std::cout << sumUpToN - sumOfSequence << '\n';
    return 0;
}
