#include <iostream>
#include <cmath>
#include <algorithm>

using std::cin;
using std::cout;

int main(int argc, char const *argv[])
{
    std::string s,t;
    cin >> s >> t;
    int s_x = 8 - (s[1] - '0'), s_y = s[0] - 'a';
    int t_x = 8 - (t[1] - '0'), t_y = t[0] - 'a';
    cout << std::max(std::abs(s_x - t_x), std::abs(s_y - t_y)) << '\n';
    while(!(s_x == t_x && s_y == t_y)){
        if(s_y < t_y){
            cout << "R";
            ++s_y;
        }
        if(s_y > t_y){
            cout << "L";
            --s_y;
        }
        if(s_x > t_x){
            cout << "U";
            --s_x;
        }
        if(s_x < t_x){
            cout << "D";
            ++s_x;
        }
        cout << '\n';
    }
    return 0;
}
