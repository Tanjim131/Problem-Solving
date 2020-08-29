#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char const *argv[])
{
    int T;
    cin >> T;
    while(T--){
        int n;
        cin >> n;
        vector <int> plays(n), clears(n);
        // at most one level specific update
        vector <int> status(1000 + 1, -1);
        bool possible = true;
        for(int i = 0 ; i < n ; ++i){
            cin >> plays[i] >> clears[i];
            if(status[plays[i]] == -1){
                status[plays[i]] = clears[i];
            } else if(status[plays[i]] != clears[i]){
                possible = false;
            }
        }
        if(!possible){
            cout << "NO" << '\n';
            continue;
        }
        for(int i = 0 ; i < n - 1 ; ++i){
            if(plays[i] > plays[i + 1]){
                possible = false;
                break;
            }
        }
        if(!possible){
            cout << "NO" << '\n';
            continue;
        }
        for(int i = 0 ; i < n - 1 ; ++i){
            if(clears[i] > clears[i + 1]){
                possible = false;
                break;
            }
        }
        if(!possible) {
            cout << "NO" << '\n';
            continue;
        }
        for(int i = 0 ; i < n ; ++i){
            if(clears[i] > plays[i]){
                possible = false;
                break;
            }
        }
        if(!possible) {
            cout << "NO" << '\n';
            continue;
        }
        // cannot clear a number of level without playing enough
        for(int i = 0 ; i < n - 1 ; ++i){
            if(clears[i + 1] - clears[i] > plays[i + 1] - plays[i]){
                possible = false;
                break;
            }
        }
        if(!possible) {
            cout << "NO" << '\n';
            continue;
        }
        cout << "YES\n";
    }
    return 0;
}
