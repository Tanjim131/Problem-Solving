#include <iostream>
#include <algorithm>

using std::cin;
using std::cout;

int main(int argc, char const *argv[])
{
    int n;
    cin >> n;
    std::string t;
    cin >> t;
    for(int i = 2 ; i <= n ; ++i){
        if(n % i == 0){
            std::reverse(t.begin(), t.begin() + i);
        }
    }
    cout << t << '\n';
    return 0;
}
