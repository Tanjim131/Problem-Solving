#include <iostream>

using std::cin;
using std::cout;

int main(int argc, char const *argv[])
{
    std::string s, t;
    cin >> s >> t;
    int i = s.length() - 1, j = t.length() - 1;
    while(i >= 0 && j >= 0 && s[i] == t[j]){
        --i, --j;
    }
    cout << i + j + 2 << '\n';
    return 0;
}
