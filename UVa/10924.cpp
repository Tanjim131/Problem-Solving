#include <iostream>
#include <unordered_map>
#include <vector>
#include <cmath>

std::unordered_map <int,int> sieve (int N){
    std::vector <int> status(N + 1, 1); // initially all are prime
    int sqrtN = sqrt(N);
    for(int i = 3 ; i <= sqrtN ; i += 2){
        if(status[i]){
            for(int j = i * i ; j <= N ; j += (i + i)){
                status[j] = 0;
            }
        }
    }
    std::unordered_map <int,int> primes;
    primes[2] = 1;
    for(int i = 1 ; i <= N ; i += 2){
        if(status[i]) primes[i] = 1;
    }
    return primes;
}

int main(int argc, char const *argv[])
{
    std::unordered_map <int,int> primes = sieve(1040);
    std::string input;
    while(std::cin >> input){
        int sum = 0;
        for(int i = 0 ; i < input.size() ; ++i){
            if(input[i] >= 'a' && input[i] <= 'z') sum += input[i] - 'a' + 1;
            else sum += input[i] - 'A' + 27;
        }
        if(primes.find(sum) != primes.end()){
            std::cout << "It is a prime word.\n";
        } else{
            std::cout << "It is not a prime word.\n";
        }
    }
    return 0;
}
