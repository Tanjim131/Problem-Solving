#include <iostream>
#include <vector>
#include <limits>
#include <algorithm>

using namespace std;

int main(int argc, char const *argv[])
{
    int n;
    cin >> n;
   
    vector <int> text_sizes(n);
    for(int i = 0 ; i < n ; ++i) cin >> text_sizes[i];
    vector <int> cost(n);
    for(int i = 0 ; i < n ; ++i) cin >> cost[i];
    
    int min_cost = numeric_limits<int>::max();
    
    for(int j = 1 ; j < n - 1 ; ++j){
        int min_left = numeric_limits<int>::max();
        for(int i = j - 1 ; i >= 0 ; --i){
            if(text_sizes[i] < text_sizes[j]) {
                min_left = min(min_left, cost[i]);
            }
        }
        if(min_left == numeric_limits<int>::max()) continue;
    
        int min_right = numeric_limits<int>::max();
        for(int k = j + 1 ; k < n ; ++k){
            if(text_sizes[k] > text_sizes[j]) {
                min_right = min(min_right, cost[k]);
            }
        }
        if(min_right == numeric_limits<int>::max()) continue;

        min_cost = min(min_cost, min_left + cost[j] + min_right);
    }

    if(min_cost == numeric_limits<int>::max()){
        cout << "-1\n";
    } else{
        cout << min_cost << '\n';
    }
    return 0;
}
