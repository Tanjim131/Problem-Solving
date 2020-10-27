#include <iostream>

using namespace std;

bool is_prime(int n){
    for(int i = 2 ; i * i <= n ; ++i){
        if(n % i == 0) return false;
    }
    return true;
}

int next_prime(int n){
    for(int i = n ; ; ++i){
        if(is_prime(i)) return i;
    }
}

int prev_prime(int n){
    for(int i = n ; ; --i){
        if(is_prime(i)) return i;
    }
}


int main(int argc, char const *argv[])
{
    for(int n ; cin >> n && n != 0 ;){
        int prime_gap = next_prime(n) - prev_prime(n);
        cout << prime_gap << '\n';
    }
    return 0;
}
