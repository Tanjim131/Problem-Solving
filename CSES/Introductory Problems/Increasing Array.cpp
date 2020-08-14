#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char const *argv[])
{
    int n;
    cin >> n;
    vector <int> v(n);
    for(int i = 0 ; i < n ; ++i) cin >> v[i];
    long long turns = 0;
    for(int i = 1 ; i < n ; ++i){
        if(v[i] < v[i - 1]){
            turns += v[i - 1] - v[i];
            v[i] = v[i - 1];
        }
    }
    cout << turns << '\n';
    return 0;
}
