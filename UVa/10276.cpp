#include <iostream>
#include <cmath>
#include <vector>

inline bool isSquare(int num){
    double sqrtNum = std::sqrt(num);
    return std::floor(sqrtNum) == std::ceil(sqrtNum);
}

bool insertIntoPeg(std::vector<int> *pegs, int index, int num){
    if(!pegs[index].empty() && !isSquare(num + pegs[index].back())) return false;
    pegs[index].emplace_back(num);
    return true;
}

int main(int argc, char const *argv[])
{
    int T;
    std::cin >> T;
    while(T--){
        int N;
        std::cin >> N;
        std::vector <int> pegs[N];
        for(int i = 1 ; ; ++i){
            // try to satisfy the constraint
            bool satisfied = false;
            for(int j = 0 ; j < N ; ++j){
                if(insertIntoPeg(pegs, j, i)){
                    satisfied = true;
                    break;
                }
            }
            if(!satisfied){
                std::cout << i - 1 << '\n';
                break;
            }
        }
    }
    return 0;
}
