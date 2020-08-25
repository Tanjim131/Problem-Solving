#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char const *argv[])
{
    int n, m;
    cin >> n >> m;
    vector <int> a(n + 1);
    for(int i = 1 ; i <= n ; ++i) cin >> a[i];
    int increment = 0;
    for(int i = 1 ; i <= m ; ++i){
        int t; cin >> t;
        if(t == 1){
            int v, x;
            cin >> v >> x;
            a[v] = x - increment;
        } else if(t == 2){
            int y;
            cin >> y;
            increment += y;
        } else{
            int q;
            cin >> q;
            cout << a[q] + increment << '\n';
        }
    }
    // vector <int> last_updated(n + 1, 0);
    // vector <int> increments(m + 1, 0); 
    // for(int i = 1 ; i <= m ; ++i){
    //     increments[i] += increments[i - 1];
    //     int t;
    //     cin >> t;
    //     if(t == 1){
    //         int v, x;
    //         cin >> v >> x;
    //         a[v] = x;
    //         last_updated[v] = i;
    //     } else if(t == 2){
    //         int y;
    //         cin >> y;
    //         increments[i] += y;
    //     } else{
    //         int q;
    //         cin >> q;
    //         cout << a[q] +  increments[i] - increments[last_updated[q]] << '\n';
    //     }
    // }
    return 0;
}
