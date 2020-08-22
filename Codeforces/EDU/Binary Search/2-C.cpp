#include <iostream>
#include <utility>

using namespace std;

bool ok(int n, int x, int y, int t){
    return t / x + (t - x) / y >= n;
}

int binary_search(int n, int x, int y){
    int low = 1, high = 2 * 1e9;
    int ans = -1;
    while(low <= high){
        int mid = (low + high) / 2;
        if(ok(n, x, y, mid)){
            ans = mid;
            high = mid - 1;
        } else{
            low = mid + 1;
        }
    }
    return ans;
}

int main(int argc, char const *argv[])
{
    int n, x, y;
    cin >> n >> x >> y;
    if(x > y) swap(x, y);
    cout << binary_search(n, x, y) << '\n';
    return 0;
}
