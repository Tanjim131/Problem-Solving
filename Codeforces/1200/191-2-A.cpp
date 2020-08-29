#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>

using namespace std;

int main(int argc, char const *argv[])
{
    int n;
    cin >> n;
    vector <int> a(n);
    // O(N^2) solution
    // vector <int> count(n + 1, 0);
    // int ones = 0;
    // for(int i = 1 ; i <= n ; ++i) {
    //     cin >> a[i];
    //     ones += a[i]; // current number of 1s 
    //     count[i] += a[i] + count[i - 1]; // count number of 1s
    // }
    // int maximum = 0;
    // for(int i = 1 ; i <= n ; ++i){
    //     for(int j = i ; j <= n ; ++j){
    //         // flip interval [i...j]
    //         int o = count[j] - count[i - 1];
    //         int l = j - i + 1;
    //         int z = l - o;
    //         // after flipping the ones will become zeroes and the zeroes will become ones
    //         maximum = max(maximum, ones - o + z);
    //     }
    // }
    // cout << maximum << '\n';

    // O(n) solution - Kadane's Algorithm - Maximum Subarray Sum
    vector <int> b(n);
    int ones = 0;
    for(int i = 0 ; i < n ; ++i){
        cin >> a[i];
        ones += a[i];
        b[i] = a[i] == 1 ? -1 : 1; // gain
    }
    int max_sum = numeric_limits<int>::min();
    for(int i = 0, current_sum = 0 ; i < n ; ++i){
        current_sum += b[i];
        max_sum = max(max_sum, current_sum);
        if(current_sum < 0){
            current_sum = 0;
        }
    }
    cout << ones + max_sum << '\n';
    return 0;
}
