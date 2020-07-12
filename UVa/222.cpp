#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <limits>
#include <iomanip>

class GasStop{
    public:
        double distance, cost;
        GasStop(){}
};

bool canReachNextStation(double current_capacity, double distanceToNextStation, double milesPG){
    double gasNeeded = current_capacity - distanceToNextStation / milesPG;
    return !(gasNeeded < 0.0);
}

double backtrack(const std::vector <GasStop> &gasStops, double distanceToDestination, double total_capacity, double current_capacity, double milesPG, double current_cost, int index = 0, int lastOilStop = -1){
    if(index == gasStops.size()){
        return current_cost;
    }
    // check if it can reach the next station / destination with remaining gas
    double distanceToNextStation = 0.0;
    if(index == gasStops.size() - 1) distanceToNextStation = distanceToDestination - gasStops[index].distance;
    else distanceToNextStation = gasStops[index + 1].distance - gasStops[index].distance;

    double milesTraveled = gasStops[index].distance - (lastOilStop != -1) * gasStops[lastOilStop].distance;
    double remGas = current_capacity - milesTraveled / milesPG;
    double ratio = remGas / total_capacity;

    double answer = std::numeric_limits <double>::max();

    if(!canReachNextStation(remGas, distanceToNextStation, milesPG)){ 
        // fill up the gas tank
        double stationCost = std::round((total_capacity - remGas) * gasStops[index].cost + 200.0) / 100.0;
        answer = backtrack(gasStops, distanceToDestination, total_capacity, total_capacity, milesPG, current_cost + stationCost, index + 1, index);
    } else{
        double ret1 = std::numeric_limits<double>::max();
        if(ratio < 0.5){
            // if it can reach the next station
            // it can only take gas at this station if less than half capcity is remaining
            double stationCost = std::round((total_capacity - remGas) * gasStops[index].cost + 200.0) / 100.0;
            ret1 = backtrack(gasStops, distanceToDestination, total_capacity, total_capacity, milesPG, current_cost + stationCost, index + 1, index);
        } 
        double ret2 = backtrack(gasStops, distanceToDestination, total_capacity, current_capacity, milesPG, current_cost, index + 1, lastOilStop);
        answer = std::min(ret1, ret2);
    }
    return answer;
}

int main(int argc, char const *argv[])
{
    int k = 0;
    double distanceToDestination;
    while(std::cin >> distanceToDestination){
        if(distanceToDestination < 0) break;
        double total_capacity, milesPG, costOrig;
        int numStops;
        std::cin >> total_capacity >> milesPG >> costOrig >> numStops;
        std::vector <GasStop> gasStops(numStops); 
        for(int i = 0 ; i < numStops ; ++i){
            std::cin >> gasStops[i].distance >> gasStops[i].cost;
        }
        std::cout << "Data Set #" << ++k << '\n'; 
        std::cout << "minimum cost = $" << std::fixed << std::setprecision(2) << backtrack(gasStops, distanceToDestination, total_capacity, total_capacity, milesPG, costOrig) << '\n';
    }
    return 0;
}
