#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

int main(int argc, char const *argv[])
{
    int T;
    std::cin >> T;
    while(T--){
        int r;
        std::cin >> r;
        std::vector <int> street_numbers(r);
        for(int i = 0 ; i < r ; ++i){
            std::cin >> street_numbers[i];
        }
        std::sort(street_numbers.begin(), street_numbers.end());
        int optimal_position = -1;
        if(street_numbers.size() % 2 == 0){
            int middle1 = street_numbers.size() / 2, middle2 = middle1 - 1;
            optimal_position = (street_numbers[middle1] + street_numbers[middle2]) / 2; // take the middle number in case of even length
        } else{
            int middle = ( street_numbers.size() - 1) / 2; // only 1 middle number in case of odd length
            optimal_position = street_numbers[middle];
        }
        int minimum_distance = 0;
        for(int i = 0 ; i < street_numbers.size() ; ++i){
            minimum_distance += std::abs(optimal_position - street_numbers[i]);
        }
        std::cout << minimum_distance << '\n';
    }
    return 0;
}
