#include <iostream>
#include <vector>
#include <limits>
#include <algorithm>

using namespace std;

int main(int argc, char const *argv[])
{
    int n, l, r, x;
    cin >> n >> l >> r >> x;
    vector <int> c(n);
    for(int i = 0 ; i < n ; ++i) cin >> c[i];
    int ways = 0;
    for(int i = 0 ; i < (1 << n) ; ++i){
        int total = 0;
        int maximum = 0;
        int minimum = numeric_limits<int>::max();
        for(int j = 0 ; j < n ; ++j){
            if(i & (1 << j)){
                total += c[j];
                maximum = max(maximum, c[j]);
                minimum = min(minimum, c[j]);
            }
        }
        if(total >= l && total <= r && maximum - minimum >= x){
            ++ways;
        }
    }
    cout << ways << '\n';
    return 0;
}
