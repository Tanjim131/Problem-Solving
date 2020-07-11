#include <iostream>
#include <tuple>
#include <vector>
#include <algorithm>

class Order{
    public:
        int source, destination, passangers;
        friend std::istream& operator >> (std::istream&, Order&);
        bool operator < (const Order &order) const{
            return std::tie(source, destination, passangers) < std::tie(order.source, order.destination, order.passangers);
        }
};

std::istream& operator >> (std::istream &in, Order &order){
    in >> order.source >> order.destination >> order.passangers;
    return in;
}

int backtrack(const std::vector <Order> &orders, int total_passangers, int current_index = 0, int current_passangers = 0, int current_profit = 0, std::vector <int> destinations = std::vector<int>(8,0)){
    if(current_index == orders.size()){
        return current_profit;
    }

    for(int i = orders[current_index].source ; i > 0 ; --i){
        if(destinations[i] > 0){
            current_passangers -= destinations[i];
            destinations[i] = 0;
        }
    }
    
    int s,d,p;
    std::tie(s,d,p) = std::tie(orders[current_index].source, orders[current_index].destination, orders[current_index].passangers);

    int ret1 = -1;
    if(current_passangers + p <= total_passangers){
        int profit = (d - s) * p;
        destinations[d] += p;
        ret1 = backtrack(orders, total_passangers, current_index + 1, current_passangers + p, current_profit + profit, destinations);
        destinations[d] -= p;
    }
    int ret2 = backtrack(orders, total_passangers, current_index + 1, current_passangers, current_profit, destinations);    

    return std::max(ret1, ret2);
}

int main(int argc, char const *argv[])
{
    int n, cityB, numOrders;
    while(std::cin >> n >> cityB >> numOrders){
        if(!n && !cityB && !numOrders) break;
        std::vector <Order> orders(numOrders);
        for(int i = 0 ; i < numOrders ; ++i){
            std::cin >> orders[i];
        }
        std::sort(orders.begin(), orders.end());
        std::cout << backtrack(orders, n) << '\n';
    }
    return 0;
}
