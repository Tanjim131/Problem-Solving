#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
#include <tuple>

using std::cin;
using std::cout;

class Triplet{
    public:
        int sumW, index, subsequence;
        Triplet(int val, int _i, int _sub) : sumW(val), index(_i), subsequence(_sub){}
        bool operator < (const Triplet &triplet) const{
            return std::tie(sumW, subsequence, index) < std::tie(triplet.sumW, triplet.subsequence, triplet.index);
        }
};

int main(int argc, char const *argv[])
{
    int k;
    cin >> k;
    std::vector <Triplet> triplets; 
    triplets.reserve(200000);
    for(int i = 0 ; i < k ; ++i){
        int n; cin >> n;
        std::vector <int> v(n);
        for(int j = 0 ; j < n ; ++j){
            cin >> v[j];
        }
        int sum = std::accumulate(v.begin(), v.end(), 0);
        for(int j = 0 ; j < n ; ++j){
            triplets.emplace_back(Triplet(sum - v[j], j + 1, i + 1));
        }
    }
    std::sort(triplets.begin(), triplets.end());
    bool possible = false;
    for(int i = 0 ; i < triplets.size() - 1 ; ++i){
        if(triplets[i].sumW == triplets[i + 1].sumW && triplets[i].subsequence != triplets[i + 1].subsequence){
            cout << "YES\n";
            cout << triplets[i].subsequence << " " << triplets[i].index << '\n';
            cout << triplets[i + 1].subsequence << " " << triplets[i + 1].index << '\n';
            possible = true;
            break;
        }
    }
    if(!possible){
        cout << "NO\n";
    }
    return 0;
}
