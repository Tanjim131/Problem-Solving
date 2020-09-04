#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <queue>

using namespace std;

int main(int argc, char const *argv[])
{
    int n, k;
    cin >> n >> k;
    vector <int> a(n);
    for(int i = 0 ; i < n ; ++i) cin >> a[i];
    string s;
    cin >> s;
    long long answer = 0;
    for(int i = 0, j = 0 ; i < s.length() ; i = j){
        // while(j < n && s[i] == s[j]) ++j;
        // sort(a.begin() + i, a.begin() + j, greater<int>());
        // for(int index = i ; index < min(i + k, j) ; ++index){
        //     answer += a[index];
        // }

        // priority queue solution
        priority_queue <int> pq;
        while(j < n && s[i] == s[j]){
            pq.push(a[j]);
            ++j;
        }
        for(int t = 0 ; t < k && !pq.empty() ; ++t){
            answer += pq.top();
            pq.pop();
        }
    }
    cout << answer << '\n';
    return 0;
}
