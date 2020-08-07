#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>

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
    cout << "YES\n";
    double div = s * 1.0 / k;
    double whole, frac;
    frac = modf(div, &whole);
    int a = whole + 1;
    int at = round(frac * k);
    int b = whole;
    int bt = k - at;
    int _max = max(a, b);
    int _min = min(a, b);
    int maxt =_max == a ? at : bt;
    int mint = _min == a ? at : bt;
    vector <int> v1{1, _max + 1};
    int index = 0;
    while(maxt--){
        cout << v1[index ^ 1] << " ";
        index ^= 1;
    }
    vector <int> v2;
    if(v1[index] == 1){
        v2 = {1, 1 + _min};
    } else{
        if(_max + _min < n){
            v2 = {_max + 1, _max + 1 + _min};
        } else{
            v2 = {_max + 1, _max + 1 - _min};
        }
    }
    index = 0;
    while(mint--){
        cout << v2[index ^= 1] << " ";
    }
    cout << '\n';
    
    return 0;
}
