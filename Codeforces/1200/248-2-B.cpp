#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector <long long> v(n + 1, 0), sorted(n + 1, 0);
    for(int i = 1 ; i <= n ; ++i) {
        cin >> v[i];
        sorted[i] = v[i];
        v[i] += v[i - 1];
    }
    sort(sorted.begin(), sorted.end());
    for(int i = 1 ; i <= n ; ++i) {
        sorted[i] += sorted[i - 1];
    }
    int m;
    cin >> m;
    while(m--){
        int type, L, R;
        cin >> type >> L >> R;
        if(type == 1){
            cout << v[R] - v[L - 1] << '\n';
        } else{
            cout << sorted[R] - sorted[L - 1] << '\n';
        }
    }
    return 0;
}
