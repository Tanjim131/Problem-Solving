#include <iostream>
#include <cmath>
#include <vector>

using std::cin;
using std::cout;

int main(int argc, char const *argv[])
{
    int n,d;
    cin >> n >> d;
    std::vector <int> s(n);
    for(int i = 0 ; i < n ; ++i){
        cin >> s[i];
    }
    int ways = 0;
    for(int i = 0 ; i < n ; ++i){
        for(int j = i + 1 ; j < n ; ++j){
            int diff = std::abs(s[i] - s[j]);
            if(diff <= d) ways += 2;
        }
    }
    cout << ways << '\n';
    return 0;
}
