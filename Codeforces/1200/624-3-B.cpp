#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;

int main(int argc, char const *argv[])
{
    int t;
    cin >> t;
    while(t--){
        int n, m;
        cin >> n >> m;
        vector <int> a(n), p(m);
        for(int i = 0 ; i < n ; ++i) cin >> a[i];
        for(int i = 0 ; i < m ; ++i) cin >> p[i];
        sort(p.begin(), p.end());
        bool possible = true;
        for(int i = 0 ; i < n && possible ; ++i){
            for(int j = 0 ; j < n - 1 ; ++j){
                if(a[j] > a[j + 1]){
                    // a[j] and a[j + 1] needs to be swapped
                    auto it = lower_bound(p.begin(), p.end(), j + 1);
                    if(it != p.end() && *it == j + 1){
                        swap(a[j], a[j + 1]);
                    } else{
                        possible = false;
                        break;
                    }
                }
            }
        }
        cout << (possible ? "YES" : "NO") << '\n';
    }
    return 0;
}
