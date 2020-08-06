#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
 
using std::cin;
using std::cout;
 
class Pair{
    public:
        int value, index;
        Pair(int _v, int _i) : value(_v), index(_i){}
        bool operator < (const Pair &pair) const{
            return value > pair.value;
        }
};
 
int main(int, char const *[])
{
    int n,k;
    cin >> n >> k;
    std::vector <Pair> v; 
    v.reserve(n);
    for(int i = 0 ; i < n ; ++i){
        int x; cin >> x;
        v.emplace_back(Pair(x, i));
    }
    std::sort(v.begin(), v.end());
    int max_profit = 0;
    for(int i = 0 ; i < k ; ++i){
        max_profit += v[i].value;
    }
    std::sort(v.begin(), v.begin() + k, [&](const Pair &p1, const Pair &p2){
        return p1.index < p2.index;
    });
    cout << max_profit << '\n';
    int prev = 0;
    for(int i = 0 ; i < k - 1 ; ++i){
        cout << v[i].index + 1 - prev << " "; // make a cut at the right (except the rightmost element)
        prev = v[i].index + 1;
    }
    cout << n - prev << '\n';
    return 0;
}