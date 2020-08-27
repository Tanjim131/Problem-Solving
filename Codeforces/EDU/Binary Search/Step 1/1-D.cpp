#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(int argc, char const *argv[])
{
    int n; cin >> n;
    vector <int> v(n);
    for(int i = 0 ; i < n ; ++i) cin >> v[i];
    sort(v.begin(), v.end());
    int k; cin >> k;
    vector <int> answers; answers.reserve(k);
    while(k--){
        int L, R;
        cin >> L >> R;
        int index1 = lower_bound(v.begin(), v.end(), L) - v.begin();
        int index2 = upper_bound(v.begin(), v.end(), R) - v.begin();
        answers.emplace_back(index2 - index1);
    }
    for(int i = 0 ; i < answers.size() ; ++i){
        cout << answers[i] << " \n"[i + 1 == answers.size()];
    }
    return 0;
}
