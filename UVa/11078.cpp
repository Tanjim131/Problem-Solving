#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>

int main(int argc, char const *argv[])
{
    int T;
    std::cin >> T;
    while(T--){
        int n; 
        std::cin >> n;
        std::vector <int> numbers(n);
        for(int i = 0 ; i < n ; ++i){
            std::cin >> numbers[i];
        }
        int max_diff = std::numeric_limits<int>::min();
        int key = numbers[0];
        for(int i = 1 ; i < numbers.size() ; ++i){
            max_diff = std::max(max_diff, key - numbers[i]);
            key = std::max(key, numbers[i]);
        }
        std::cout << max_diff << '\n';
    }
    return 0;
}
