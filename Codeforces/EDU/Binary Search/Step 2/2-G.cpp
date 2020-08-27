#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool ok(const vector <int> &g, int k, long long councils){
    long long sum = 0;
    for(int i = 0 ; i < (int) g.size() ; ++i){
        long long limit = min(1LL * g[i], councils);
        sum += limit;
    }
    return sum / councils >= k;
}

long long binary_search(const vector <int> &g, int k){
    long long low = 1, high = 1e11;
    long long ans = 0;
    while(low <= high){
        long long mid = (low + high) / 2;
        if(ok(g, k, mid)){
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
    int k;
    cin >> k;
    int n;
    cin >> n;
    vector <int> g(n);
    for(int i = 0 ; i < n ; ++i){
        cin >> g[i];
    }
    cout << binary_search(g, k) << '\n';
    return 0;
}
