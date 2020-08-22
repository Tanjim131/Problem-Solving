#include <iostream>

using namespace std;


bool isValid(int value, int n){
    return value >= 1 && value <= n;
}

int main(int argc, char const *argv[])
{
    int n, a, b, c, d;
    cin >> n >> a >> b >> c >> d;
    long long ways = 0;
    for(int i = 1 ; i <= n ; ++i){
        int p = i;
        int q = p + b - c;
        int s = p + a - d;
        int t = p + a + b - c - d;
        if(isValid(q, n) && isValid(s, n) && isValid(t, n)){
            ways += n;
        }
    }
    cout << ways << '\n';
    return 0;
}
