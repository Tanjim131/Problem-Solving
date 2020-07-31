#include <iostream>

using std::cin;
using std::cout;

int main(int argc, char const *argv[])
{
    int q;
    cin >> q;
    while(q--){
        int L1,R1,L2,R2;
        cin >> L1 >> R1 >> L2 >> R2;
        if(L1 != L2){
            cout << L1 << " " << L2 << '\n';
        } else{
            cout << L1 << " " << R2 << '\n';
        }
    }
    return 0;
}
