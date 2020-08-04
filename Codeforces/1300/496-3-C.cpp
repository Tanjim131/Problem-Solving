#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using std::cin;
using std::cout;

std::vector <int> generate_powers_of_two(){
    std::vector <int> powers;
    for(int i = 0 ; i < 31 ; ++i){
        int power = 1 << i;
        powers.emplace_back(1 << i);
    }
    return powers;
}

int main(int argc, char const *argv[])
{
    std::vector <int> powers = generate_powers_of_two();
    int n;
    cin >> n;
    std::vector <int> v(n);
    std::map <int,int> freq;
    for(int i = 0 ; i < n ; ++i){
        cin >> v[i];
        ++freq[v[i]];
    }
    std::sort(v.begin(), v.end());
    int counter = 0;
    for(int i = 0 ; i < v.size() ; ++i){
        bool possible = false;
        for(int j = powers.size() - 1 ; j >= 0 && powers[j] > v[i] ; --j){
            int required = powers[j] - v[i];
            auto it = std::lower_bound(v.begin(), v.end(), required);
            if(it != v.end() && *it == required && (v[i] != required || v[i] == required && freq[v[i]] > 1)){
                possible = true;
                break;
            }
        }
        if(!possible){
            ++counter;
        }
    }
    cout << counter << '\n';
    return 0;
}
