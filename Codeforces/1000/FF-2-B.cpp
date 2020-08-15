#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(int argc, char const *argv[])
{
    string s;
    cin >> s;
    int k; 
    cin >> k;
    vector <int> w(26);
    int maximum = -1; 
    for(int i = 0 ; i < 26 ; ++i) {
        cin >> w[i];
        maximum = max(maximum, w[i]);
    }
    int answer = 0;
    for(int i = 0 ; i < s.length() ; ++i){
        answer += w[s[i] - 'a'] * (i + 1);
    }
    answer += maximum * (k * s.length() + k * (k + 1) / 2);
    cout << answer << '\n';
    return 0;
}
