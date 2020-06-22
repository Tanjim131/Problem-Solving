#include <iostream>
#include <vector>

class PowerRate{
    public:
        int range, price;
        PowerRate(){}
        PowerRate(int _r, int _p): range(_r), price(_p){}
};

// this function calculates consumption given bill 
int computeConsumption(int bill){
    std::vector <PowerRate> powerRates{{100, 2}, {9900, 3}, {990000, 5}};
    int consumption = 0;
    for(int i = 0 ; i < powerRates.size() ; ++i){
        int rangePrice = powerRates[i].price * powerRates[i].range;
        if(rangePrice <= bill){
            consumption += powerRates[i].range;
            bill -= rangePrice;
        } else{
            consumption += bill / powerRates[i].price;
            bill = 0;
            break;
        }
    }
    if(bill) consumption += bill / 7;
    return consumption;
}

// this function calculates bill given consumption 
int computeBill(int consumption){
    std::vector <PowerRate> powerRates{{100, 2}, {9900, 3}, {990000, 5}};
    int bill = 0;
    for(int i = 0 ; i < powerRates.size() ; ++i){
        int rangePrice = powerRates[i].price * powerRates[i].range;
        if(powerRates[i].range <= consumption){
            bill += rangePrice;
            consumption -= powerRates[i].range;
        } else{
            bill += powerRates[i].price * consumption;
            consumption = 0;
            break;
        }
    }
    if(consumption) bill += 7 * consumption;
    return bill;
}

int computeStatus(int myConsumption, int neighborConsumption, int absoluteDifference){
    int myBill = computeBill(myConsumption);
    int neighborBill = computeBill(neighborConsumption);
    int difference = neighborBill - myBill;
    if(difference == absoluteDifference) return 0;
    if(difference < absoluteDifference) return -1; // need to increase difference, i.e. need to decrease myBill or myConsumption
    return 1; // need to decrease difference, i.e. need to increase myBill or myConsumption
}

int binarySearch(int totalConsumption, int absoluteDifference){
    int low = 1, high = totalConsumption;
    int ans = -1;
    while(low <= high){
        int mid = low + (high - low) / 2;
        int myConsumption = mid;
        int neighborConsumption = totalConsumption - mid;
        if(myConsumption > neighborConsumption){
            high = mid - 1;
            continue;
        }
        int status = computeStatus(myConsumption, neighborConsumption, absoluteDifference);
        if(!status){
            ans = computeBill(myConsumption);
            break;
        } else if(status == -1){
            // need to decrease my consumption
            high = mid - 1;
        } else{
            // need to increase my consumption
            low = mid + 1;
        }
    }
    return ans;
}

int main(int argc, char const *argv[])
{
    int totalBill, absoluteDifference;
    while(std::cin >> totalBill >> absoluteDifference){
        if(!totalBill && !absoluteDifference) break;
        // first find out the total consumption
        int totalConsumption = computeConsumption(totalBill);
        // then do binary search on totalConsumption
        std::cout << binarySearch(totalConsumption, absoluteDifference) << '\n';
    }
    return 0;
}
