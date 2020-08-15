#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
    int n, m;
    cin >> n >> m;
    long long tt = 0;
    int cur_house = 1;
    for(int i = 0 ; i < m ; ++i){
        int x; cin >> x;
        int t = (x - cur_house) % n;
        if(t < 0) t += n;
        tt += t;
        cur_house = x;
    }
    cout << tt << '\n';
    return 0;
}
