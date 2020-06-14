#include <iostream>

#pragma GCC target ("sse4.2")

// x << y = x * 2^y

inline bool isSetBit(int i, int index){
    return i & (1 << index);
}

void decimalToBinary(int i, int N){
    for(int j = N - 1 ; j >= 0 ; --j){
        if(isSetBit(i, j)){
            std::cout << '1';
        } else{
            std::cout << '0';
        }
    }
}

void printSolutions(int N, int H){
    for(int i = 0 ; i < (1 << N) ; ++i){
        if(__builtin_popcount(i) == H){
            decimalToBinary(i, N);
            std::cout << '\n';
        }
    }
}

int main(int argc, char const *argv[])
{
    int T, k = 0;
    std::cin >> T;
    while(T--){
        int N,H;
        std::cin >> N >> H;
        if(k > 0) std::cout << '\n';
        printSolutions(N, H);
        ++k;
    }
    return 0;
}