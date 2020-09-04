#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// struct Pair{
//     int value, index;
//     bool operator < (const Pair &p) const{
//         return value < p.value;
//     }
// };

int main(int argc, char const *argv[])
{
    int n;
    cin >> n;
    //vector <Pair> a(n);
    constexpr int MAX = 1e6;
    vector <int> a(n), count(MAX + 1, 0);
    long long sum = 0;
    for(int i = 0 ; i < n ; ++i){
        // cin >> a[i].value;
        // a[i].index = i + 1;
        // sum += a[i].value;
        cin >> a[i];
        sum += a[i];
        ++count[a[i]];
    }
    vector <int> answers; 
    answers.reserve(n);
    // O(n) solution
    for(int i = 0 ; i < n ; ++i){
        long long rem = sum - a[i];
        --count[a[i]];
        // let a[j] be the index such that a[j] - rem == a[j] ==> a[j] == rem / 2
        if(rem % 2 == 0 && rem / 2 <= MAX && count[rem / 2] > 0){
            answers.emplace_back(i + 1);
        }
        ++count[a[i]];
    }
    // O(nlogn) solution
    // sort(a.begin(), a.end());
    // for(int i = 0 ; i < n ; ++i){
    //     if(sum - a[i].value == 2 * a[i == n - 1 ? n - 2 : n - 1].value){
    //         answers.emplace_back(a[i].index);
    //     }
    // }
    cout << answers.size() << '\n';
    for(int i = 0 ; i < answers.size() ; ++i){
        cout << answers[i] << " \n"[i + 1 == answers.size()];
    }
    return 0;
}
