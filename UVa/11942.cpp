#include <iostream>
#include <vector>
#include <algorithm>

int main(int argc, char const *argv[])
{
    int T;
    std::cin >> T;
    std::cout << "Lumberjacks:\n";
    while(T--){
        std::vector <int> beards(10);
        for(int i = 0 ; i < 10 ; ++i){
            std::cin >> beards[i];
        }
        
        std::vector <int> shortToLong(beards.begin(), beards.end());
        std::sort(shortToLong.begin(), shortToLong.end());

        std::vector <int> longToShort(beards.begin(), beards.end());
        std::sort(longToShort.begin(), longToShort.end(), std::greater<int>());

        if(beards == shortToLong || beards == longToShort){
            std::cout << "Ordered\n";
        } else{
            std::cout << "Unordered\n";
        }
    }
    return 0;
}
