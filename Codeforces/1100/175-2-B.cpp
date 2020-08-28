#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
    int n, k;
    cin >> n >> k;
    int index = n - 1 - k;
    for(int i = 1 ; i <= index ; ++i){
        cout << i << " ";
    }
    for(int i = index, j = n ; i < n ; ++i, --j){
        cout << j << " \n"[i + 1 == n];
    }
    return 0;
}
