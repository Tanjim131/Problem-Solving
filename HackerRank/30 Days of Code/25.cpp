#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

bool isPrime(int n){
    if(n == 1) return false;
    int sqrtN = static_cast<int>(sqrt(n));
    for(int i = 2 ; i <= sqrtN ; ++i){
        if(n % i == 0) return false;
    }
    return true;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int T;
    cin >> T;
    while(T--){
        int n;
        cin >> n;
        cout << (isPrime(n) == true ? "Prime" : "Not prime") << '\n';
    }   
    return 0;
}
