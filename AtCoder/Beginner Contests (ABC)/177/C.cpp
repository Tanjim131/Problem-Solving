#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char const *argv[])
{
    int n;
    cin >> n;
    vector <int> a(n + 1);
    vector <long long> cumulative_sum(n + 1, 0);
    for(int i = 1 ; i <= n ; ++i){
        cin >> a[i];
        cumulative_sum[i] += a[i] + cumulative_sum[i - 1];
    }
    constexpr int MOD = 1000000007;
    long long sum = 0;
    for(int i = 1 ; i < n ; ++i){
        sum = (sum + (((cumulative_sum[n] - cumulative_sum[i]) % MOD) * a[i]) % MOD) % MOD;
    }
    cout << sum << '\n';
    return 0;
}
