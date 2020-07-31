#include <iostream>

using std::cin;
using std::cout;

int main(int argc, char const *argv[])
{
    int n;
    cin >> n;
    int current = 1;
    for(int i = 1 ; i <= n - 1 ; ++i){
        current = (current + i) % n;
        cout << (!current ? n : current);
        if(i != n - 1) cout << " ";
    }
    cout << '\n';
    return 0;
}
