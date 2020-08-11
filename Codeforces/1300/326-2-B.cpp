#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

/*
Well lets present N like N = p[1] ^ a[1] * p[2] ^ a[2] * ... * p[k] ^ a[k]; 
So any divisor of N can be presented like p[1] ^ s[1] * p[2] ^ s[2] * ... * p[k] ^ s[k], where 0 <= s[i] <= a[i]. 
So if we try to maximize the answer we should make s[i] as much as possible but we cant make any s[i] > 1, 
because then our 'answer' would be divisible by p[i] * p[i]. 
That's why the actual answer is p[1] * p[2] * ... * p[k]
*/

vector <int> sieve(int N = 1000003){
    vector <int> status(N + 1, 1);
    for(int i = 3 ; i * i <= N ; i += 2){
        if(status[i] == 1){
            for(int j = i * i ; j <= N ; j += i + i){
                status[j] = 0;
            }
        }
    }
    vector <int> primes; primes.reserve(80000);
    primes.emplace_back(2);
    for(int i = 3 ; i <= N ; i += 2){
        if(status[i] == 1) primes.emplace_back(i);
    }
    return primes;
}

// struct Divisor{
//     long long value;
//     int count;
//     Divisor(long long _v, int _c) : value(_v), count(_c){}  
// };

// vector <Divisor> compute_prime_divisors(long long n, const vector <int> &primes){
//     int sqrtN = sqrt(n);
//     vector <Divisor> divisors; 
//     divisors.reserve(2 * sqrtN);
//     for(int i = 0 ; primes[i] <= sqrtN && n > 1 ; ++i){
//         if(n % primes[i] == 0){
//             int counter = 0;
//             while(n % primes[i] == 0){
//                 ++counter;
//                 n /= primes[i];
//             }
//             divisors.emplace_back(Divisor(primes[i], counter));
//             sqrtN = sqrt(n);
//         }
//     }
//     if(n > 1){
//         divisors.emplace_back(Divisor(n, 1));
//     }
//     return divisors;
// }

// void recurse(vector <long long> &divisors, const vector <Divisor> &prime_divisors, int index = 0, long long product = 1){
//     if(index == prime_divisors.size()){
//         //cout << "HERE\n";
//         divisors.emplace_back(product);
//         return;
//     }
//     //cout << "product = " << product << " index = " << index << '\n';
//     for(int i = 0 ; i <= prime_divisors[index].count ; ++i){
//         long long res = __gnu_cxx::power(prime_divisors[index].value, i);
//         //cout << "i = " << i << " res = " << res << " product * res = " << product * res << " prime = " << prime_divisors[index].value << '\n';
//         recurse(divisors, prime_divisors, index + 1, product * res);
//     }
// }

// vector <long long> get_all_divisors(long long n, const vector <int> &primes){
//     vector <Divisor> prime_divisors = compute_prime_divisors(n, primes);
//     int sqrtN = sqrt(n);
//     //cout << "n = " << n << '\n';
//     // for(int i = 0 ; i < prime_divisors.size() ; ++i){
//     //     cout << prime_divisors[i].value << " " << prime_divisors[i].count << '\n';
//     // } 
//     vector <long long> all_divisors; all_divisors.reserve(2 * sqrtN);
//     recurse(all_divisors, prime_divisors);
//     return all_divisors;
// }

// bool isPerfectSquare(long long n){
//     long long sqrtN = sqrt(n);
//     return sqrtN * sqrtN == n;
// }

// bool isLovely(long long n, const vector <int> &primes){
//     vector <long long> all_divisors = get_all_divisors(n, primes);
//     sort(all_divisors.begin(), all_divisors.end());
//     for(int i = all_divisors.size() - 1 ; i > 0 ; --i){
//         if(isPerfectSquare(all_divisors[i])) return false;
//     }
//     return true;
// }

// long long solve(long long n, const vector <int> &primes){
//     vector <long long> all_divisors = get_all_divisors(n, primes);
//     sort(all_divisors.begin(), all_divisors.end());
//     long long answer = -1;
//     for(int i = all_divisors.size() - 1 ; i >= 0 ; --i){
//         if(!isLovely(all_divisors[i], primes)) continue;
//         answer = all_divisors[i];
//         break;
//     }
//     return answer;
// }

int main(int argc, char const *argv[])
{
    //vector <int> primes = sieve();
    long long n;
    cin >> n;
    //cout << solve(n, primes) << '\n';
    int sqrtN = sqrt(n);
    long long answer = 1;
    for(int i = 2 ; i <= sqrtN && n > 1 ; ++i){
        if(n % i == 0){
            answer *= i;
            while(n % i == 0){
                n /= i;
            }
            sqrtN = sqrt(n);
        }
    }
    answer *= n; 
    cout << answer << '\n';
    return 0;
}
