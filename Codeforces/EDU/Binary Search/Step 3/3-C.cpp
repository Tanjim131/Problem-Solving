#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool ok(const vector <int> &a, int k, int distance){
    int index = 0;
    for(int i = 0 ; i < k - 1 ; ++i){ // k - 1 distances for k cows
        auto it = lower_bound(a.begin() + index, a.end(), a[index] + distance);
        if(it == a.end()) return false;
        index = it - a.begin();
    }
    return true;
}

int binary_search(const vector <int> &a, int k){
    int low = 1, high = 1e9;
    int ans = -1;
    while(low <= high){
        int mid = (low + high) / 2;
        if(ok(a, k, mid)){
            ans = mid;
            low = mid + 1;
        } else{
            high = mid - 1;
        }
    }
    return ans;
}

int main(int argc, char const *argv[])
{
    int n, k;
    cin >> n >> k;
    vector <int> a(n);
    for(int i = 0 ; i < n ; ++i) cin >> a[i];
    cout << binary_search(a, k) << '\n';
    return 0;
}
