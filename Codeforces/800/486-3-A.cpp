#include <iostream>
#include <vector>
#include <set>

using std::cin;
using std::cout;

int main(int argc, char const *argv[])
{
    int n,k;
    cin >> n >> k;
    std::set <int> distinct;
    std::vector <int> indices; indices.reserve(n);
    for(int i = 0 ; i < n ; ++i){
        int x; cin >> x;
        if(distinct.size() < k && distinct.find(x) == distinct.end()){
            distinct.insert(x);
            indices.emplace_back(i + 1);
        }
    }
    if(indices.size() == k){
        cout << "YES\n";
        for(auto index : indices){
            cout << index << " ";
        }
        cout << '\n';
    } else{
        cout << "NO\n";
    }
    return 0;
}
