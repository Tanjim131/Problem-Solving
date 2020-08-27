#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>

using namespace std;

int main(int argc, char const *argv[])
{
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector <int> a(n), sorted(n);
        int minimum = numeric_limits<int>::max();
        for(int i = 0 ; i < n ; ++i){
            cin >> a[i];
            sorted[i] = a[i];
            minimum = min(minimum, a[i]);
        }
        sort(sorted.begin(), sorted.end());
        bool possible = true;
        for(int i = 0 ; i < n ; ++i){
            if(sorted[i] == a[i]) continue;
            int g = __gcd(minimum, a[i]);
            if(g != minimum){
                possible = false;
                break;
            }
        }
        cout << (possible ? "YES" : "NO") << '\n';
    }
    return 0;
}
