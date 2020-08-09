#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(int argc, char const *argv[])
{
    int n;
    cin >> n;
    vector <int> v(n);
    for(int i = 0 ; i < n ; ++i){
        cin >> v[i];
    }
    sort(v.begin(), v.end());
    long long waiting_time = v[0];
    int not_disappointed = 1; // the first person will always be satisfied
    for(int i = 1 ; i < n ; ++i){
        if(waiting_time > v[i]){
            continue; // he will be disappointed anyway, no point in serving him now, send at the end of the queue
        }
        waiting_time += v[i];
        ++not_disappointed;
    }
    cout << not_disappointed << '\n';
    return 0;
}
