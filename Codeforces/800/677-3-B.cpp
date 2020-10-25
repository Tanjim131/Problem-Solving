#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char const *argv[])
{
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector <int> v(n);
        int leftmost = -1, rightmost = -1;
        for(int i = 0 ; i < n ; ++i) {
            cin >> v[i];
            if(v[i] == 1){
                if(leftmost == -1) leftmost = i;
                rightmost = i;
            }
        }
        int count = 0;
        for(int i = leftmost ; i <= rightmost ; ++i){
            count += v[i] == 0;
        }
        cout << count << '\n';
    }
    return 0;
}
