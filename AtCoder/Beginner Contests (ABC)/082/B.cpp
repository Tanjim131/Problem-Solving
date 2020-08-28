#include <iostream>
#include <algorithm>

using namespace std;

int main(int argc, char const *argv[])
{
    string s, t;
    cin >> s >> t;
    sort(s.begin(), s.end());
    sort(t.rbegin(), t.rend());
    if(s < t){
        cout << "Yes\n";
    } else{
        cout << "No\n";
    }
    return 0;
}
