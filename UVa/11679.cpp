#include <iostream>
#include <vector>

int main(int argc, char const *argv[])
{
    int B, N;
    while(std::cin >> B >> N){
        if(!B && !N) break;
        
        std::vector <int> cash_reserve(B);
        for(int i = 0 ; i < B ; ++i) {
            std::cin >> cash_reserve[i];
        }
    
        for(int i = 0 ; i < N ; ++i){
            int D,C,V;
            std::cin >> D >> C >> V;
            cash_reserve[C - 1] += V;
            cash_reserve[D - 1] -= V;
        }
        
        bool isPossible = true;
        for(int i = 0 ; i < B ; ++i){
            if(cash_reserve[i] < 0){
                isPossible = false;
                break;
            }
        }
        std::cout << (isPossible ? "S" : "N") << '\n';
    }
    return 0;
}
