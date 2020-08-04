#include <iostream>
#include <vector>
#include <algorithm>

using std::cin;
using std::cout;

int main(int argc, char const *argv[])
{
    int n, k;
    cin >> n >> k;
    std::string s;
    cin >> s;
    std::vector <int> initFreq(26, 0);
    for(int i = 0 ; i < s.length() ; ++i){
        ++initFreq[s[i] - 'a'];
    }
    std::vector <int> remFreq(initFreq.begin(), initFreq.end());
    for(int i = 0 ; i < initFreq.size() ; ++i){ 
        remFreq[i] = std::max(remFreq[i] - k, 0);
        k -= initFreq[i];
        if(k <= 0) break;
    }
    std::vector <int> runningFreq(26, 0);
    for(int i = 0 ; i < s.length() ; ++i){
        int index = s[i] - 'a';
        if(!remFreq[index]) continue;
        int ignore = initFreq[index] - remFreq[index];
        if(++runningFreq[index] > ignore){
            cout << s[i];
        }
    }
    cout << '\n';
    return 0;
}
