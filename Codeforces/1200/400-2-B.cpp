#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

vector<int> sieve(int N = 100001){
    vector <int> status(N + 1, 1);
    for(int i = 4 ; i <= N ; i += 2) status[i] = 2;
    for(int i = 3 ; i * i <= N ; i += 2){
        if(status[i] == 1){
            for(int j = i * i ; j <= N ; j += i + i){
                status[j] = 2;
            }
        }
    }
    return status;
}

int main(int argc, char const *argv[])
{
    vector <int> colors = sieve();
    int n;
    cin >> n;
    unordered_set <int> distinct_colors(colors.begin() + 2, colors.begin() + n + 2);
    cout << distinct_colors.size() << '\n';
    for(int i = 1 ; i <= n ; ++i){
        cout << colors[i + 1] << " \n"[i == n];
    }
    return 0;
}
