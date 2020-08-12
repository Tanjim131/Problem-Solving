#include <iostream>
#include <vector>

using namespace std;

vector <int> sieve(int N = 1000003){
    vector <int> status(N + 1, 1);
    status[0] = status[1] = 0;
    for(int i = 4 ; i <= N ; i += 2) status[i] = 0;
    for(int i = 3 ; i * i <= N ; i += 2){
        if(status[i] == 1){
            for(int j = i * i ; j <= N ; j += i + i){
                status[j] = 0;
            }
        }
    }
    return status;
}

int sum_of_digits(int n){
    int sum = 0;
    while(n != 0){
        sum += n % 10;
        n /= 10;
    }
    return sum;
}

vector <int> preprocess(const vector <int> &is_prime, int N = 1000000){
    vector <int> v(N + 1, 0);
    for(int i = 1 ; i <= N ; ++i){
        int sum = sum_of_digits(i);
        if(is_prime[i] == 1 && is_prime[sum] == 1){
            v[i] = 1;
        }
        v[i] += v[i - 1];
    }
    return v;
}

int main(int argc, char const *argv[])
{
    vector <int> is_prime = sieve();
    vector <int> v = preprocess(is_prime);
    int N;
    cin >> N;
    while(N--){
        int t1, t2;
        cin >> t1 >> t2;
        cout << v[t2] - v[t1 - 1] << '\n';
    }
    return 0;
}
