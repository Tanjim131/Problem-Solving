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
        std::set <int> sums;
        for(int i = 0 ; i < n ; ++i){
            for(int j = i + 1 ; j < n ; ++j){
                sums.insert(w[i] + w[j]);
            }
        }
        int maximum = 0;
        for(auto sum : sums){
            int counter = 0;
            std::vector <int> flag(n, 0);
            for(int i = 0 ; i < n ; ++i){
                if(flag[i]) continue;
                for(int j = i + 1 ; j < n ; ++j){
                    if(!flag[i] && !flag[j] && w[i] + w[j] == sum) {
                        ++counter;
                        flag[i] = flag[j] = 1;
                    }
                }
            }
            maximum = std::max(maximum, counter);
        }
        cout << maximum << '\n';
    }
    return 0;
}
