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
        int index = lower_bound(v.begin(), v.end(), q) - v.begin(); // 1-based indexing
        cout << ++index << '\n';
    }
    return 0;
}
