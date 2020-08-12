#include <iostream>
#include <vector>
#include <limits>
#include <algorithm>
#include <bitset>

using namespace std;

int recurse(const vector <int> &a, const vector <int> &b, int &counter, int index = 0, int OR = 0){
    if(index == a.size()){
        ++counter;
        return OR;
    }
    int answer = numeric_limits <int>::max();
    for(int i = 0 ; i < b.size() ; ++i){
        int ret = recurse(a, b, counter, index + 1, OR | (a[index] & b[i]));
        answer = min(answer, ret);
    }
    return answer;
}

// void recurse(const vector <int> &a, const vector <int> &b, int index = 0, vector <int> c = vector <int>()){
//     if(index == a.size()){
//         int OR = 0;
//         for(int i = 0 ; i < c.size() ; ++i) OR |= c[i];
//         if(OR == 147){
//             for(int i = 0 ; i < c.size() ; ++i){
//                 cout << c[i] << " ";
//             }
//             cout << '\n';
//         }
//         return;
//     }
//     int answer = numeric_limits <int>::max();
//     for(int i = 0 ; i < b.size() ; ++i){
//         c.emplace_back(a[index] & b[i]);
//         recurse(a, b, index + 1, c);
//         //answer = min(answer, ret);
//         c.pop_back();
//     }
// }

int main(int argc, char const *argv[])
{
    int n, m;
    cin >> n >> m;
    vector <int> a(n), b(m);
    for(int i = 0 ; i < n ; ++i) cin >> a[i];
    for(int i = 0 ; i < m ; ++i) cin >> b[i];
    vector <int> c(n);
    // for(int i = 0 ; i < n ; ++i){
    //     int mlz = 0, minimum = numeric_limits <int>::max();
    //     for(int j = 0 ; j < m ; ++j){
    //         int res = a[i] & b[j];
    //         bitset <9> b(res);
    //         cout << "a[i] = " << a[i] << " & b[j] = " << b[j] << " = " << res << " " << b.to_string() << '\n';
    //         int lz = __builtin_clz(res);
    //         if(lz >= mlz){
    //             mlz = lz;
    //             minimum = min(minimum, res);
    //         }
    //     }
    //     bitset <9> b(minimum);
    //     cout << "a[i] = " << a[i] << " minimum = " << minimum << " " << b.to_string() << '\n';
    //     c[i] = minimum;
    // }
    // int OR = 0;
    // for(int i = 0 ; i < n ; ++i) OR |= c[i];
    // cout << OR << '\n';
    int counter = 0;
    recurse(a, b, counter);
    cout << counter << '\n';
    //cout << recurse(a, b) << '\n';
    return 0;
}
