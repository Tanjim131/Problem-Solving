#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(int argc, char const *argv[])
{
    int n;
    cin >> n;
    vector <int> entry(n + 1), exit(n + 1);
    for(int i = 0 ; i < n ; ++i){
        cin >> entry[i + 1];
    }
    for(int i = 0 ; i < n ; ++i){
        int x; cin >> x;
        exit[x] = i + 1;
    }
    vector <int> c(n + 1, 0);
    for(int i = 0 ; i < n ; ++i){
        c[i + 1] = exit[entry[i + 1]];
    }
    int fined = 0, maximum = 0;
    for(int i = 0 ; i < n ; ++i){
        maximum = max(maximum, c[i]);
        if(c[i + 1] < maximum){
            ++fined;
        }
    }
    cout << fined << '\n';
    return 0;
}
