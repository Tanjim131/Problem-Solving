#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(int argc, char const *argv[])
{
    int n, k;
    cin >> n >> k;
    vector <int> v(n);
    for(int i = 0 ; i < n ; ++i) cin >> v[i];
    while(k--){
        int q;
        cin >> q;
        auto it = lower_bound(v.begin(), v.end(), q);
        if(it != v.end() && *it == q){
            cout << "YES\n";
        } else{
            cout << "NO\n";
        }
    }
    return 0;
}
