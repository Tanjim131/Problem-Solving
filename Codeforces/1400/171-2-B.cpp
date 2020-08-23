#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(int argc, char const *argv[])
{
    // ios_base::sync_with_stdio(false);
    // cin.tie(0);
    int n, t;
    cin >> n >> t;
    vector <int> b(n + 1, 0);
    for(int i = 1 ; i <= n ; ++i){
        cin >> b[i];
        b[i] += b[i - 1];
    }
    int maximum = -1;
    for(int i = 1 ; i <= n ; ++i){
        int index = upper_bound(b.begin() + i, b.end(), t + b[i - 1]) - (b.begin() + 1);
        maximum = max(maximum, index - i + 1);
    }
    cout << maximum << '\n';
    return 0;
}
