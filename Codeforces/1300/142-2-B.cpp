#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;

vector <int> sieve(int N){
    vector <int> status(N + 1, 1); // initially all are prime
    status[0] = status[1] = 0;
    int sqrtN = sqrt(N);
    for(int i = 4 ; i <= N ; i += 2) status[i] = 0;
    for(int i = 3 ; i <= sqrtN ; i += 2){
        if(status[i] == 1){
            for(int j = i * i ; j <= N ; j += i + i){
                status[j] = 0;
            }
        }
    }
    return status;
}

bool isPerfectSquare(long long n){
    long long sqrtN = sqrt(n);
    return sqrtN * sqrtN == n;
}

// a number has three divisors iff it is a perfect square and it's square root is a prime number
bool check(long long n, const vector <int> &prime_status){
    int sqrtN = sqrt(n);
    return isPerfectSquare(n) && prime_status[sqrtN] == 1; 
}

int main(int argc, char const *argv[])
{
    //ios_base::sync_with_stdio(false); cin.tie(NULL);
    vector <int> prime_status = sieve(1000000);
    int n;
    cin >> n;
    for(int i = 0 ; i < n ; ++i){
        long long x; cin >> x;
        if(check(x, prime_status)){
            cout << "YES\n";
        } else{
            cout << "NO\n";
        }
    }
    return 0;
}
