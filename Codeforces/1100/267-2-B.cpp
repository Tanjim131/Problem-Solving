#include <iostream>
#include <vector>

using namespace std;

#pragma GCC target("sse4.2")

int main(int argc, char const *argv[])
{
    int n, m, k;
    cin >> n >> m >> k;
    vector <int> players(m + 1);
    for(int i = 0 ; i < m + 1 ; ++i){
        cin >> players[i];
    }
    int friends = 0;
    for(int i = 0 ; i < m ; ++i){
        int XOR = players[i] ^ players[m];
        int diff = __builtin_popcount(XOR);
        if(diff <= k) ++friends;
    }
    cout << friends << '\n';
    return 0;
}
