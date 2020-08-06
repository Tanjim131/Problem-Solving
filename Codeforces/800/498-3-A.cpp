#include <iostream>
#include <vector>

using std::cin;
using std::cout;

int main(int argc, char const *argv[])
{
    int n;
    cin >> n;
    std::vector <int> v(n);
    for(int i = 0 ; i < n ; ++i){
        cin >> v[i];
        if(v[i] % 2 == 0) --v[i];
    }
    for(int i = 0 ; i < n ; ++i){
        cout << v[i] << " ";
    }
    return 0;
}
