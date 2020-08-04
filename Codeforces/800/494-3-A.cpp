#include <iostream>
#include <vector>
#include <algorithm>

using std::cin;
using std::cout;

int main(int argc, char const *argv[])
{
    int n;
    std::cin >> n;
    std::vector <int> freq(101, 0);
    int minimum = -1;
    for(int i = 0 ; i < n ; ++i){
        int x; cin >> x;
        ++freq[x];
        minimum = std::max(minimum, freq[x]);
    }
    cout << minimum << '\n';
    return 0;
}
