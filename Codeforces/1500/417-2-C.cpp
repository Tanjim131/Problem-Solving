#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

bool ok(const vector <int> &a, int S, int k){
    vector<long long> v(a.begin(), a.end());
    for(int i = 0 ; i < v.size() ; ++i){
        v[i] += 1LL * (i + 1) * k;
    }
    sort(v.begin(), v.end());
    long long sum = accumulate(v.begin(), v.begin() + k, 0LL);
    return S >= sum;
}

// O(Nlog^2N) or O(2 * N * logN) solution

int binary_search(const vector <int> &a, int S){
    int low = 0, high = a.size();
    int ans = 0;
    while(low <= high){
        int mid = (low + high) / 2;
        if(ok(a, S, mid)){
            ans = mid;
            low = mid + 1;
        } else{
            high = mid - 1;
        }
    }
    return ans;
}

int compute_sum(vector <int> &a, int k){
    for(int i = 0 ; i < a.size() ; ++i){
        a[i] += (i + 1) * k;
    }
    sort(a.begin(), a.end());
    long long sum = accumulate(a.begin(), a.begin() + k, 0);
    return sum;
}

int main(int argc, char const *argv[])
{
    int n, S;
    cin >> n >> S;
    vector <int> a(n);
    for(int i = 0 ; i < n ; ++i){
        cin >> a[i];
    }
    int k = binary_search(a, S);
    int sum = compute_sum(a, k);
    cout << k << " " << sum << '\n';
    return 0;
}
