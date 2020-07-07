#include <iostream>
#include <cmath>
#include <limits>

inline bool isPerfectSquare(int determinant){
    double sqrtDeterminant = std::sqrt(determinant);
    int f = static_cast<int>(std::floor(sqrtDeterminant));
    int c = static_cast<int>(std::ceil(sqrtDeterminant));
    return f == c;
}

std::pair<int,int> decompose(int p, int q){
    int determinant = 12 * q - 3 * p * p;
    if(determinant < 0 || !isPerfectSquare(determinant)) return {-1,-1}; // no solution
    int numerator = -3 * p + static_cast<int>(std::sqrt(determinant));
    if(numerator <= 0 || numerator % 6 != 0) return {-1,-1}; // no solution
    int y = numerator / 6;
    int x = y + p;
    return {x,y};
}

std::pair<int,int> factors(int n){
    std::pair<int,int> answer = {-1,-1};
    int sqrtN {static_cast<int>(std::sqrt(n))};
    for(int i = sqrtN ; i >= 1 ; --i){ // for y_min, we need p_max, the first solution we get will guarantee y_min
        if(n % i == 0){
            int p = i;
            int q = n / i;
            std::pair <int,int> solution = decompose(p,q);
            if(solution != std::make_pair(-1,-1)){
                answer = solution;
                break;
            }
        }
    }
    return answer;
}

int main(int argc, char const *argv[])
{
    int n;
    while(std::cin >> n && n){
        std::pair <int,int> answer = factors(n);
        if(answer != std::make_pair(-1,-1)){
            std::cout << answer.first << " " << answer.second << '\n';
        } else{
            std::cout << "No solution\n";
        }
    }
    return 0;
}
