#include <iostream>
#include <cmath>

int main(int argc, char const *argv[])
{
    int T;
    std::cin >> T;
    while(T--){
        long long a,b,c;
        std::cin >> a >> b >> c;

        /* first question */
        
        if(a * b - c <= 0){
            // solution exists for x % b != 0 (a * b - c < 0 is necessary for x % b == 0)
            std::cout << "1 "; // x = 1 will always satisfy x % b != 0 as b >=2 
        } else{
            // solution does not exist for x % b == 0
            long long numerator = c * (b - 1); // r >= 1, make the numerator as large as possible
            long long denominator = a * b - c;
            double result = numerator * 1.0 / denominator; // x < (c * (b - r)) / (ab - c)

            int x = static_cast<int>(std::floor(result));
            if(result == std::floor(result)) --x;
            
            if(x > 0){
                std::cout << "1 ";
            } else{
                std::cout << "-1 ";
            }
        }
        
        /* second equation */

        if(a * b - c <= 0){
            std::cout << "-1\n";
        } else{
            std::cout << b << '\n';
        }

    }
    return 0;
}
