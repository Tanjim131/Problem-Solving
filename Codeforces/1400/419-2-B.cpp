#include <iostream>
#include <vector>
#include <limits>
#include <algorithm>

using namespace std;

constexpr int MAX = 200000;

int main(int argc, char const *argv[])
{
    // ios_base::sync_with_stdio(false);
    // cin.tie(0);
    int n, k, q;
    cin >> n >> k >> q;
    vector <int> admissible_count(MAX + 2, 0);
    int start = numeric_limits<int>::max(), end = -1;
    for(int i = 0 ; i < n ; ++i) {
        int L, R;
        cin >> L >> R;
        start = min(start, L);
        end = max(end, R + 1);
        ++admissible_count[L];
        --admissible_count[R + 1];
    }
    for(int i = start ; i <= end ; ++i){
        admissible_count[i] += admissible_count[i - 1];
    }
    vector <int> range_admissible_count(200000 + 1, 0);
    for(int i = 1 ; i <= MAX ; ++i){
        if(admissible_count[i] >= k){
            ++range_admissible_count[i];
        }
        range_admissible_count[i] += range_admissible_count[i - 1];
    }
    for(int i = 0 ; i < q ; ++i){
        int a, b;
        cin >> a >> b;
        cout << range_admissible_count[b] - range_admissible_count[a - 1] << '\n';
    }
    return 0;
}
