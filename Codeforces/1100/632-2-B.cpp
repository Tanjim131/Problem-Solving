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
        vector <int> a(n), b(n);
        int fno = -1, fpo = -1; // index of first negative one and first positive one respectively
        for(int i = 0 ; i < n ; ++i) {
            cin >> a[i];
            if(a[i] == -1 && fno == -1){
                fno = i;
            }
            if(a[i] == 1 && fpo == -1){
                fpo = i;
            }
        }
        for(int i = 0 ; i < n ; ++i) cin >> b[i];
        bool possible = true;
        for(int i = n - 1 ; i >= 0 ; --i){
            if(b[i] == a[i]) continue;
            if(b[i] < a[i] && (fno == -1 || fno >= i)){
                possible = false;
                break;
            }
            if(b[i] > a[i] && (fpo == -1 || fpo >= i)){
                possible = false;
                break;
            }   
        }
        cout << (possible ? "YES" : "NO") << '\n';
    }
    return 0;
}
