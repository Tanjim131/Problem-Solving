#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char const *argv[])
{
    int n;
    cin >> n;
    vector <vector<int>> tiers(n + 1);
    for(int i = 0 ; i < 2 * n ; ++i){
        int x; cin >> x;
        tiers[x].emplace_back(i);
    }
    long long d = 0;
    int sp = 0, dp = 0;
    // choosing greedily for either Sasha or Dima didn't give correct answer
    for(int i = 1 ; i <= n ; ++i){
        // sasha goes to 0 and dima goes to 1
        long long da = abs(tiers[i][0] - sp) + abs(tiers[i][1] - dp);
        // or sasha goes to 1 and dima goes to 0
        long long db = abs(tiers[i][1] - sp) + abs(tiers[i][0] - dp);
        if(da < db){
            d += da;
            sp = tiers[i][0];
            dp = tiers[i][1];
        } else{
            d += db;
            sp = tiers[i][1];
            dp = tiers[i][0];
        }
    }
    cout << d << '\n';
    return 0;
}
