#include <iostream>

long long solveRecurrence(int n, int k){
    if(k == 0) return 1;
    return (n * solveRecurrence(n - 1, k - 1)) / k; // multiplication needs to be done before division
}

int main(int argc, char const *argv[])
{
    int n,k;
    while(std::cin >> n >> k){
        if(!n && !k) break;
        k = std::min(k, n - k);
        std::cout << solveRecurrence(n,k) << '\n';
    }
    return 0;
}
