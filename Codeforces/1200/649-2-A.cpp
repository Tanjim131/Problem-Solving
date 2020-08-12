#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(int argc, char const *argv[])
{
    int T;
    cin >> T;
    while(T--){
        int n, x;
        cin >> n >> x;
        vector <int> a(n);
        int min_index = -1;
        int length1 = -1, length2 = -1;
        for(int i = 0 ; i < n ; ++i) {
            cin >> a[i];
            if(i > 0){
                a[i] += a[i - 1];
            }
            if(min_index == -1 && a[i] % x != 0){
                min_index = i;
            }
            if(a[i] % x != 0){
                length1 = i + 1;
            } else{
                length2 = i;
            }
        }
        if(min_index != -1){
            length2 -= min_index;
        } else{
            length2 = -1;
        }
        cout << max(length1, length2) << '\n';
    }
    return 0;
}
