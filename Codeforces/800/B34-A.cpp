#include <iostream>
#include <vector>
#include <limits>
#include <cmath>

using std::cin;
using std::cout;


int main(int argc, char const *argv[])
{
    int n;
    cin >> n;
    std::vector <int> s(n);
    for(int i = 0 ; i < n ; ++i){
        cin >> s[i];
    }
    int minimum = std::numeric_limits <int>::max();
    int p = -1, q = -1;
    for(int i = 0 ; i < n ; ++i){
        int a = s[i];
        int b = s[(i + 1) % n];
        int diff = std::abs(a - b);
        if(minimum > diff){
            minimum = diff;
            p = i + 1;
            q = (i + 1) % n + 1;
        }
    }
    cout << p << " " << q << '\n';
    return 0;
}
