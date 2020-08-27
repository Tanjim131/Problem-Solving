#include <iostream>
#include <limits>
#include <algorithm>

using namespace std;

int compute_digits(int n){
    int counter = 0;
    while(n != 0){
        ++counter;
        n /= 10;
    }
    return counter;
}

int main(int argc, char const *argv[])
{
    long long N;
    cin >> N;
    int answer = numeric_limits<int>::max();
    for(int i = 1 ; 1LL * i * i <= N ; ++i){
        if(N % i == 0){
            int A = i;
            int B = N / i;
            int dA = compute_digits(A);
            int dB = compute_digits(B);
            answer = min(answer, max(dA, dB));
        }
    }
    cout << answer << '\n';
    return 0;
}
