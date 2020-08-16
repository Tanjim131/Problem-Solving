#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char const *argv[])
{
    int n;
    cin >> n;
    vector <int> h(n);
    for(int i = 0 ; i < n ; ++i) cin >> h[i];
    int t = 0;
    int cur_height = 0;
    for(int i = 0 ; i < n ; ++i){
        if(i > 0){
            if(h[i - 1] > h[i]){
                cur_height = h[i];
                t += h[i - 1] - h[i];
            }
            ++t;
        }
        if(cur_height != h[i]){
            t += h[i] - cur_height;
            cur_height = h[i];
        }
        ++t;
    }
    cout << t << '\n';
    return 0;
}
