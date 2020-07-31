#include <iostream>
#include <algorithm>

int main(int argc, char const *argv[])
{
    int N,K,X,Y;
    std::cin >> N >> K >> X >> Y;
    int fee = std::min(N,K) * X + std::max(N - K, 0) * Y;
    std::cout << fee << '\n';    
    return 0;
}
