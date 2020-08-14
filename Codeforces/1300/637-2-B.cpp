#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(int argc, char const *argv[])
{
    // ios_base::sync_with_stdio(false);
    // cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        int n, k;
        cin >> n >> k;
        vector <int> v(n + 1);
        for(int i = 1 ; i <= n ; ++i) cin >> v[i];
        vector <int> is_peak(n + 1, 0);
        for(int i = 1 ; i <= n ; ++i){
            if(i == 1 || i == n) continue;
            if(v[i] > v[i - 1] && v[i] > v[i + 1]) is_peak[i] = 1;
        }
        vector <int> range_pick_count(n + 1, 0);
        for(int i = 1 ; i <= n ; ++i){
            if(is_peak[i] != 0){
                ++range_pick_count[i];
            }
            range_pick_count[i] += range_pick_count[i - 1];
        }
        int max_picks = 0, optimal_start = 1;
        for(int i = 1 ; i <= n ; ++i){
            int start = i;
            int end = min(i + k - 1, n);
            if(start == end) continue;
            int picks = range_pick_count[end - 1] - range_pick_count[start];
            if(max_picks < picks){
                max_picks = picks;
                optimal_start = i;
            }
        }
        cout << max_picks + 1 << " " << optimal_start << '\n';
    }
    return 0;
}
