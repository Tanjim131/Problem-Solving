#include <iostream>
#include <algorithm>

using namespace std;

int main(int argc, char const *argv[])
{
    int n,m;
    cin >> n >> m;
    if(n % 2 == 0){
        int mid1 = n / 2, mid2 = mid1 + 1;
        if(m == mid1){
            cout << min(mid1 + 1, n) << '\n';
        } else if(m == mid2){
            cout << max(mid2 - 1, 1) << '\n';
        } else if(m > mid2){
            cout << max(m - 1, 1) << '\n';
        } else if(m < mid1){
            cout << min(m + 1, n) << '\n';
        }
    } else{
        int mid = (n + 1) / 2;
        if(m == mid){
            cout << max(mid - 1, 1) << '\n';
        } else if(m < mid){
            cout << min(m + 1, n) << '\n';
        } else{
            cout << max(m - 1, 1) << '\n';
        }
    }
    return 0;
}
