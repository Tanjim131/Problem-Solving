#include <iostream>
#include <limits>
#include <algorithm>

using namespace std;

int main(int argc, char const *argv[])
{
    // O(N^2) solution
    string s, t;
    cin >> s >> t;
    int minimum = numeric_limits<int>::max();
    int diff = s.length() - t.length();
    for(int i = 0 ; i <= diff ; ++i){
        // place t at position i and count mismatch
        int mismatch = 0;
        for(int j = i, k = 0 ; k < t.length() ; ++j, ++k){
            if(s[j] != t[k]) ++mismatch;
        }
        minimum = min(minimum, mismatch);
    }
    cout << minimum << '\n';
    return 0;
}
