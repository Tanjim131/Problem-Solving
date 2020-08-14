#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
    int q;
    cin >> q;
    while(q--){
        long long n;
        cin >> n;
        int moves = 0;
        while(n != 1){
            if(n % 2 != 0 && n % 3 != 0 && n % 5 != 0){
                moves = -1;
                break;
            }
            if(n % 2 == 0){
                n /= 2;
            } else if(n % 3 == 0){
                n /= 3;
                n *= 2;
            } else if(n % 5 == 0){
                n /= 5;
                n *= 4;
            }
            ++moves;
        }
        cout << moves << '\n';
    }
    return 0;
}
