#include <iostream>

std::string addition(const std::string &numberA, const std::string &numberB){
    int M = numberA.length();
    std::string sum(M, '0');

    int carry = 0;
    for(int i = M - 1 ; i >= 0 ; --i){
        int s = (numberA[i] - '0') + (numberB[i] - '0') + carry;
        sum[i] = (s % 10) + '0';
        carry = s / 10;
    }
    
    return sum;
}

int main(int argc, char const *argv[])
{
    int T, k = 0; 
    std::cin >> T;
    while(T--){
        int M;
        std::cin >> M;
        std::string numberA(M, '0'), numberB(M, '0'); // sum is guaranteed to not exceed M digits
        for(int i = 0 ; i < M ; ++i){
            std::cin >> numberA[i] >> numberB[i];
        }        
        if(k > 0) std::cout << '\n';
        std::cout << addition(numberA, numberB) << '\n';
        ++k;
    }
    return 0;
}
