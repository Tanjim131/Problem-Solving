#include <iostream>
#include <algorithm>
#include <limits>
#include <sstream>
#include <vector>

int compute_gcd(const std::vector <int> &numbers){
    int max_gcd = -1;
    for(int i = 0 ; i < numbers.size() ; ++i){
        for(int j = i + 1 ; j < numbers.size() ; ++j){
            max_gcd = std::max(max_gcd, std::__gcd(numbers[i], numbers[j]));
        }
    }
    return max_gcd;
}

int main(int argc, char const *argv[])
{
    int T;
    std::cin >> T;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::string input;
    while(T--){
        std::getline(std::cin, input);
        std::vector <int> numbers; numbers.reserve(100);
        {
            std::istringstream iss(input);
            int token;
            while(iss >> token){
                numbers.emplace_back(token);
            }
        }
        std::cout << compute_gcd(numbers) << '\n';
    }
    return 0;
}
