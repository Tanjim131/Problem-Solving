#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
    int n, p, q;
    cin >> n >> p >> q;
    string s;
    cin >> s;
    // find non-negative solutions to px + qy = n
    // Complexity: O(n^2)
    int x = -1, y = -1;
    // for(int i = 0 ; i <= n ; ++i){
    //     for(int j = 0 ; j <= n ; ++j){
    //         if(p * i + q * j == n){
    //             x = i;
    //             y = j;
    //             break;
    //         }
    //     }
    // }
    // Complexity: O(n)
    for(int i = 0 ; i <= n / p ; ++i){ // iterate all possible values for x
        // check if (n - p * i) % q == 0 
        if((n - p * i) % q == 0){
            x = i;
            y = (n - p * i) / q;
            break;
        }
    }
    if(x == -1 && y == -1){
        cout << "-1\n";
    } else{
        //cout << "x = " << x << " y = " << y << '\n';
        cout << x + y << '\n';
        int index = 0;
        while(x--){
            for(int i = 0 ; i < p ; ++i){
                cout << s[index++];
            }
            cout << '\n';
        }
        while(y--){
            for(int i = 0 ; i < q ; ++i){
                cout << s[index++];
            }
            cout << '\n';
        }
    }
    return 0;
}
