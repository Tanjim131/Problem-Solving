#include <iostream>
#include <algorithm>
#include <limits>

using std::cin;
using std::cout;

int main(int argc, char const *argv[])
{
    int n;
    cin >> n;
    int minimum = std::numeric_limits <int>::max();
    int sMin = -1; 
    for(int i = 0 ; i < n ; ++i){
        int x; cin >> x;
        if(minimum > x){
            sMin = minimum;
            minimum = x;
        } else if(minimum < x){
            sMin = std::min(sMin, x);
        }
    }
    if(sMin == std::numeric_limits <int>::max()){
        cout << "NO\n";
    } else{
        cout << sMin << '\n';
    }
    return 0;
}
