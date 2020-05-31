#include <iostream>
#include <vector>
#include <queue>

int isAvailable(const std::vector <int> &status){
    // returns the first parking space if there is an available one
    // otherwise returns 0
    for(int i = 1 ; i < status.size() ; ++i){
        if(!status[i]) return i;
    }
    return 0;
}

int give_space_and_return_revenue(int car_id, int slot_id, std::vector<int> &status, 
                                    std::vector<int> &car_slot, const std::vector<int> &car_weights, 
                                    const std::vector<int> &parking_space_rates)
{
    status[slot_id] = 1; // occupied
    car_slot[car_id] = slot_id; // keep tab of where the car has parked
    return car_weights[car_id] * parking_space_rates[slot_id];
}

int main(int argc, char const *argv[])
{
    int N,M;
    std::cin >> N >> M;
    std::vector <int> parking_space_rates(N + 1), car_weights(M + 1), status(N + 1, 0), car_slot(M + 1);
    for(int i = 1 ; i <= N ; ++i){
        std::cin >> parking_space_rates[i];
    }
    for(int i = 1 ; i <= M ; ++i){
        std::cin >> car_weights[i];
    }
    std::queue <int> waiting_list;
    int revenue = 0;
    for(int i = 1 ; i <= 2 * M ; ++i){
        int car_id; 
        std::cin >> car_id;
        if(car_id > 0){
            // the cark 'num' is trying to park
            // check if there's available space
            int ret = isAvailable(status);
            if(!ret){
                // no space 
                // add to queue
                waiting_list.push(car_id);
            } else{
                // there is space
                // give space and collect revenue
                revenue += give_space_and_return_revenue(car_id, ret, status, car_slot, car_weights, parking_space_rates);
            }
        } else{
            // a car is leaving 
            // first mark the space as not occupied
            car_id *= -1;
            status[car_slot[car_id]] = 0;
            // check if there's any car in waiting list
            if(!waiting_list.empty()){
                // there are cars waiting
                // while there's available slot, try to give one
                while(!waiting_list.empty()){
                    int ret = isAvailable(status);
                    if(!ret) break;
                    int car_id = waiting_list.front(); // take the first car from the queue
                    revenue += give_space_and_return_revenue(car_id, ret, status, car_slot, car_weights, parking_space_rates); 
                    waiting_list.pop(); // remove car from queue
                }
            }
        }
    }

    std::cout << revenue << '\n';

    return 0;
}
