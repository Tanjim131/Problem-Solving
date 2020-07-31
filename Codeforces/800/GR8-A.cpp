#include <iostream>
#include <algorithm>

using std::cin;
using std::cout;

int main(int argc, char const *argv[])
{
    int T;
    cin >> T;
    while(T--){
        int a,b,n;
        cin >> a >> b >> n;
        int counter = 0;
        while(a <= n && b <= n){
            if(a > b) b += a;
            else a += b;
            ++counter;
            //cout << "a = " << a << " b = " << b << '\n';
        }
        cout << counter << '\n';
    }
    return 0;
}
