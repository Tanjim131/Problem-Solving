#include <iostream>

int main(int argc, char const *argv[])
{
    int N, B, H, W;
    while(std::cin >> N >> B >> H >> W){
        int answer = B + 1;
        for(int i = 0 ; i < H ; ++i){
            int cost_per_person; 
            std::cin >> cost_per_person;
            for(int i = 0 ; i < W ; ++i){
                int number_of_available_beds; 
                std::cin >> number_of_available_beds;
                if(number_of_available_beds >= N){
                    answer = std::min(answer, N * cost_per_person);
                }
            }
        }
        if(answer > B){
            std::cout << "stay home\n";
        } else{
            std::cout << answer << '\n';
        }
    }
    return 0;
}
