#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
    int K;
    cin >> K;
    if(K % 2 == 0){
        cout << "-1\n";
    } else{
        int rem = 0;
        for(int i = 1 ; i <= 1001000 ; ++i){
            rem = (rem * 10 + 7) % K;
            if(!rem){
                cout << i << '\n';
                break;
            }
        }
        if(rem){
            cout << "-1\n";
        }
    }
    return 0;
}
