#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>

using std::cin;
using std::cout;

int main(int argc, char const *argv[])
{
    int n, k;
    cin >> n >> k;
    std::vector <int> v;
    v.reserve(n);
    std::unordered_set <int> us;
    for(int i = 0 ; i < n ; ++i){
        int x; cin >> x;
        if(us.find(x) == us.end()){
            us.insert(x);
            v.emplace_back(x);
        }
    }
    std::sort(v.begin(), v.end());
    int cur_index = 0;
    int subtract = 0;
    for(int i = 0 ; i < k ; ++i){
        if(cur_index == us.size()){
            cout << "0\n";
            continue;
        }
        int current = v[cur_index++] - subtract;
        cout << current << '\n';
        subtract += current;
    }
    return 0;
}
