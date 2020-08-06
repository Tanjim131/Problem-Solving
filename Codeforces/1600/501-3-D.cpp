#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#include <cassert>

using namespace std;

int main(int argc, char const *argv[])
{
    long long n,k,s;
    cin >> n >> k >> s;
    long long temp = s;
    if(k > s || (n - 1) * k < s){
        cout << "NO\n";
        return 0;
    }
    int counter = 0;
    do{
        if(s < k) break;
        s -= k - 1;    
        ++counter;
        //cout << "s = " << s << " counter = " << counter << '\n';
    } while(s > n - 1);
    assert((k - 1) * counter + s == temp);
    cout << "YES\n";
    if(counter > s){
        int index = 0;
        std::vector <int> v{1, counter + 1};    
        while(--k){
            cout << v[index ^= 1] << " ";
        }
        if(v[index] + s < n){
            cout << v[index] + s << '\n';
        } else{
            cout << std::abs(v[index] - s) << '\n';
        }
    } else{
        int index = 0;
        std::vector <int> v{(int) s - counter + 1, (int) s + 1};
        while(k--){
            cout << v[index ^= 1] << " ";
        }
    }
    return 0;
}
