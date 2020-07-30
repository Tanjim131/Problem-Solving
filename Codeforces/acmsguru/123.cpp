#include <iostream>

using std::cin;
using std::cout;

int main(int argc, char const *argv[])
{
    int K;
    cin >> K;
    if(K < 3){
        cout << K << '\n';
    } else{
        int f_1 = 1, f_2 = 1;
        int sum = f_1 + f_2;
        for(int i = 3 ; i <= K ; ++i){
            int f_n = f_1 + f_2;
            sum += f_n;
            f_1 = f_2;
            f_2 = f_n;
        }
        cout << sum << '\n';
    }
    return 0;
}
