#include <iostream>
#include <vector>
#include <algorithm>

int main(int argc, char const *argv[])
{
    int n,m,c, k = 0;
    while(std::cin >> n >> m >> c){
        if(!n && !m && !c) break;
        std::vector <int> capacities(n), state(n, 0), operations(m);
        for(int i = 0 ; i < n ; ++i){
            std::cin >> capacities[i];
        }
        bool blown = false;
        int maxPowerConsumption = -1;
        int currentPowerConsumption = 0;
        for(int i = 0 ; i < m ; ++i){
            std::cin >> operations[i];
        }
        for(int i = 0 ; i < m ; ++i){
            int deviceID = operations[i] - 1;
            state[deviceID] ^= 1;
            if(state[deviceID]) currentPowerConsumption += capacities[deviceID];
            else currentPowerConsumption -= capacities[deviceID];
            if(currentPowerConsumption > c){
                blown = true;
                break;
            }
            maxPowerConsumption = std::max(maxPowerConsumption, currentPowerConsumption);
        }
        if(blown){
            std::cout << "Sequence " << ++k << "\nFuse was blown.\n";
        } else{
            std::cout << "Sequence " << ++k << "\nFuse was not blown.\n";
            std::cout << "Maximal power consumption was " << maxPowerConsumption << " amperes.\n";
        }
        std::cout << '\n';
    }
    return 0;
}
