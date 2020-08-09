#include <iostream>
#include <algorithm>
#include <limits>
#include <cmath>

using namespace std;

int main(int argc, char const *argv[])
{
    int T;
    cin >> T;
    while(T--){
        int n;
        cin >> n;
        if(n % 2 == 0){
            cout << n / 2 << " " << n / 2 << '\n';
        } else{
            bool isPrime = true;
            for(int i = 3 ; i * i <= n ; i += 2){
                if(n % i == 0){
                    int a = i;
                    int b = n / i;
                    cout << b << " " << (i - 1) * b << '\n';
                    isPrime = false;
                    break;
                }
            }
            if(isPrime){
                cout << "1 " << n - 1 << '\n';
            }
        }
    }
    return 0;
}
