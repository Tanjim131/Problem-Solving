#include <iostream>
#include <algorithm>

using namespace std;

int main(int argc, char const *argv[])
{
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        string s;
        cin >> s;
        string answer;
        for(int i = 0 ; i < s.length() ; i += 2){
            // substring i runs from [i to i + n)
            answer += s[i];
        }
        cout << answer << '\n';
    }
    return 0;
}
