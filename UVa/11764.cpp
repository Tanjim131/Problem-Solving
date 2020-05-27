#include <iostream>
#include <vector>

int main(int argc, char const *argv[])
{
    int T, k = 0; 
    std::cin >> T;
    while(T--){
        int N; 
        std::cin >> N;
        std::vector <int> heights(N);
        for(int i = 0 ; i < N ; ++i){
            std::cin >> heights[i];
        }

        int low = 0, high = 0;
        for(int i = 0 ; i < N - 1 ; ++i){
            if(heights[i] < heights[i + 1]){
                ++high;
            } else if(heights[i] > heights[i + 1]){
                ++low;
            }
        }
        std::cout << "Case " << ++k << ": " << high << " " << low << '\n';
    }
    return 0;
}
