#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>
#include <ext/numeric>

using namespace std;

class Pair{
    public:
        int prime, count;

        Pair(int _prime, int _count) : prime(_prime), count(_count){}
        bool operator < (const Pair &p) const{
            return prime > p.prime;
        }
};

int main(int argc, char const *argv[])
{
    for(string line ; getline(cin, line) ; ){
        istringstream iss(line);
        int b, e;
        iss >> b;
        if(!b) break;
        iss >> e;
        long long number = __gnu_cxx::power(b, e);
        while(iss >> b >> e){
            number *= __gnu_cxx::power(b, e);
        }
        --number;
        vector <Pair> prime_factorization;
        if(number % 2 == 0){
            int count = 0;
            while(number % 2 == 0){
                ++count;
                number /= 2;
            }
            prime_factorization.push_back(Pair(2, count));
        }
        for(int i = 3 ; i * i <= number ; i += 2){
            if(number % i == 0){
                int count = 0;
                while(number % i == 0){
                    ++count;
                    number /= i;
                }
                prime_factorization.push_back(Pair(i, count));
            }
        }
        if(number > 1) prime_factorization.push_back(Pair(number, 1));
        sort(prime_factorization.begin(), prime_factorization.end());
        for(int i = 0 ; i < prime_factorization.size() ; ++i){
            cout << prime_factorization[i].prime << " " << prime_factorization[i].count;
            if(i + 1 != prime_factorization.size()) cout << " ";
        }
        cout << '\n';
    }
    return 0;
}
