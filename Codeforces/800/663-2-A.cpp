#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char const *argv[])
{
    int T;
    cin >> T;
    while(T--){
        int n;
        cin >> n;
        for(int i = 0 ; i < n ; ++i){
            cout << i + 1;
            if(i != n - 1) cout << " ";
        }
        cout << '\n';
    }
    return 0;
}
