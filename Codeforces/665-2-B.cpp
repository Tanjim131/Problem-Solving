#include <iostream>
#include <algorithm>

using namespace std;

int main(int argc, char const *argv[])
{
    int t;
    cin >> t;
    while(t--){
        int x1, y1, z1, x2, y2, z2;
        cin >> x1 >> y1 >> z1 >> x2 >> y2 >> z2;
        int sum = 0;
        int q = min(z1, y2);
        sum += q * 2;
        z1 -= q;
        y2 -= q;
        z2 -= min(z1, z2);
        z2 -= min(x1, z2);
        y1 -= min(y1, x2);
        y1 -= min(y1, y2);
        sum -= z2 * 2;
        cout << sum << '\n';
    }    
    return 0;
}
