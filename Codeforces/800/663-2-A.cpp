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
        for(int i = n ; i > 0 ; --i){
            cout << i << " ";
        }
        cout << '\n';
    }
    return 0;
}
