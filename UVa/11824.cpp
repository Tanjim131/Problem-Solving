#include <iostream>
#include <vector>
#include <algorithm>
#include <ext/numeric>

int compute(const std::vector <int> &land_costs, int threshold = 5000000){
    int cost = 0; // first tried with long long, but int also passes the test cases
    for(int i = 0 ; i < land_costs.size() ; ++i){
        cost += 2 * __gnu_cxx::power(land_costs[i], i + 1);
        if(cost > threshold){
            cost = -1;
            break;
        }
    }
    return cost;
}

int main(int argc, char const *argv[])
{
    int T;
    std::cin >> T;
    while(T--){
        std::vector <int> land_costs; 
        land_costs.reserve(40);
        {
            int n;
            while(std::cin >> n && n){
                land_costs.emplace_back(n);
            }
        }
        std::sort(land_costs.begin(), land_costs.end(), std::greater<int>());
        int cost = compute(land_costs);
        if(cost == -1){
            std::cout << "Too expensive\n";
        } else{
            std::cout << cost << '\n';
        }
    }
    return 0;
}
