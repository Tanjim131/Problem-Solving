#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using std::cin;
using std::cout;

class Pair{
    public:
        int value, freq;
        Pair(int _v, int _f) : value(_v), freq(_f){}
};

// greedy solution will work because all less values of coins are divisors of all greater values of coins

int main(int argc, char const *argv[])
{
    int n, q;
    cin >> n >> q;
    std::map <int,int> freq;
    for(int i = 0 ; i < n ; ++i){
        int x; cin >> x;
        ++freq[x];
    }
    std::vector <Pair> v;
    for(auto it : freq){
        v.push_back({it.first, it.second});
    }
    for(int i = 0 ; i < q ; ++i){
        int amount; 
        cin >> amount;
        int counter = 0;
        for(int i = v.size() - 1 ; i >= 0 ; --i){
            if(v[i].value > amount) continue;
            int quot = amount / v[i].value;
            int times = std::min(quot, v[i].freq);
            amount -= v[i].value * times;
            counter += times;
            if(amount <= 0) break;
        }
        if(amount > 0){
            cout << "-1\n";
        } else{
            cout << counter << '\n';
        }
    }
    return 0;
}
