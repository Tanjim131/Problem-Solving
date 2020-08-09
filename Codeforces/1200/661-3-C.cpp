#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using std::cin;
using std::cout;

int main(int, char const *[])
{
    int T;
    cin >> T;
    while(T--){
        int n;
        cin >> n;
        std::vector <int> w(n);
        for(int i = 0 ; i < n ; ++i){
            cin >> w[i];
        }
        // O(n^3) solution
        // std::set <int> sums;
        // for(int i = 0 ; i < n ; ++i){
        //     for(int j = i + 1 ; j < n ; ++j){
        //         sums.insert(w[i] + w[j]);
        //     }
        // }
        // int maximum = 0;
        // for(auto sum : sums){
        //     int counter = 0;
        //     std::vector <int> flag(n, 0);
        //     for(int i = 0 ; i < n ; ++i){
        //         if(flag[i]) continue;
        //         for(int j = i + 1 ; j < n ; ++j){
        //             if(!flag[i] && !flag[j] && w[i] + w[j] == sum) {
        //                 ++counter;
        //                 flag[i] = flag[j] = 1;
        //             }
        //         }
        //     }
        //     maximum = std::max(maximum, counter);
        // }
        // cout << maximum << '\n';
        
        // O(n^2) solution
        int maximum = 0;
        // minimum weight = 2 , maximum weight = 2 * n
        for(int total_weight = 2 ; total_weight <= 2 * n ; ++total_weight){
            std::vector <int> weight_counts(total_weight + 1, 0);
            int pairs = 0;
            for(int i = 0 ; i < n ; ++i){
                if(total_weight <= w[i]) continue;
                if(weight_counts[total_weight - w[i]] > 0){
                    --weight_counts[total_weight - w[i]];
                    ++pairs;
                } else{
                    ++weight_counts[w[i]];
                }
            }
            maximum = std::max(maximum, pairs);
        }
        cout << maximum << '\n';
    }
    return 0;
}
