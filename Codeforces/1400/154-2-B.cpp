#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>

using namespace std;

int main(int argc, char const *argv[])
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int n;
    cin >> n;
    vector <int> c(n);
    for(int i = 0 ; i < n ; ++i){
        cin >> c[i];
    }
    // O(nlogn solution)
    sort(c.begin(), c.end());
    int minimum = numeric_limits<int>::max();
    for(int i = 0 ; i < n ; ++i){
        // for each i, find the maximum contiguous subarray that satisfies y <= 2x
        int high = upper_bound(c.begin() + i , c.end(), 2 * c[i]) - c.begin() - 1;
        int count = high - i + 1;
        minimum = min(minimum, n - count);
    }
    cout << minimum << '\n';
    return 0;
}
