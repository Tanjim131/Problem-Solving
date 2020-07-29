#include <iostream>

using std::cin;
using std::cout;

int main(int argc, char const *argv[])
{
    int n,k;
    long long A,B;
    cin >> n >> k >> A >> B;
    if(k == 1){
        std::cout << (n - 1) * A << '\n';
        return 0;
    }
    long long cost = 0;
    while(n != 1){
        int rem = n % k;
        if(!rem){
            int result = n / k;
            long long costA = (n - result) * A;
            if(costA < B){
                cost += costA;
            } else{
                cost += B;
            }
            n = result;
        } else{
            if(rem == n) {
                cost += (n - 1) * A;
                n = 1;
            }
            else{
                cost += rem * A;
                n -= rem;
            }
        }
    }
    std::cout << cost << '\n';
    return 0;
}
