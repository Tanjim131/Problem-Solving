#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(int argc, char const *argv[])
{
    int T;
    cin >> T;
    while(T--){
        int n;
        cin >> n;
        vector <long long> a(n);
        
        long long y = 0;
        
        for(int i = 0 ; i < n ; ++i){
            cin >> a[i];
            y += a[i];
        }

        for(int i = 1 ; i < n ; ++i){
            a[i] += a[i - 1];
        }

        bool possible = false, updated = false;
        long long minimum = 0;
        for(int i = 0 ; i < n ; ++i){
            if(a[i] <= minimum){
                minimum = a[i];
                updated = true;
            }
            if(a[i] - minimum >= y){
                if(i != n - 1 || updated){
                    possible = true;
                    break;
                }
            }
        }
        cout << (possible ? "NO" : "YES") << '\n';
    }
    return 0;
}
