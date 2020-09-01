#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

bool ok(const vector <int> &a, int k, long long sum){
    int segments = 1;
    long long curSum = 0;
    for(int i = 0 ; i < a.size() && segments <= k ; ++i){
        if(a[i] > sum) return false; // no individual elements can be greater than maximize sum
        if(curSum + a[i] > sum){ // if any elements (value of each element <= sum), when added together, exceeds sum, then create a new segment
            curSum = a[i]; // new segments initial values
            ++segments; 
            continue;
        } 
        curSum += a[i]; // otherwise just keep adding elements to the current segment
    }
    return segments <= k; // if segment < k, then we can just arbitrarily place segments until segment == k
}

long long binary_search(const vector <int> &a, int k){
    long long low = *min_element(a.begin(), a.end()); // a segment cannot have a sum lower than the minimum element
    long long high = accumulate(a.begin(), a.end(), 0LL); // a segment cannot have have a sum greater than the sum of all elements
    long long ans = -1;
    while(low <= high){
        long long mid = (low + high) / 2;
        if(ok(a, k, mid)){ // this "sum" values satisfies constraints
            ans = mid;
            high = mid - 1; // look if a lower value also satisfies constraints (minimizing maximum sum)
        } else{
            low = mid + 1; // otherwise we have no option but to look for a higher value
        }
    }
    return ans;
}

int main(int argc, char const *argv[])
{
    int n, k;
    cin >> n >> k;
    vector <int> a(n);
    for(int i = 0 ; i < n ; ++i){
        cin >> a[i];
    }
    cout << binary_search(a, k) << '\n';
    return 0;
}
