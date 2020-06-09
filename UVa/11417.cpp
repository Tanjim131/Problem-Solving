#include <iostream>
#include <algorithm>

int main(int argc, char const *argv[])
{
    int N;
    while(std::cin >> N && N){
        int G = 0;
        for(int i = 1 ; i < N ; ++i){
            for(int j = i + 1 ; j <= N ; ++j){
                G += std::__gcd(i,j);
            }
        }
        std::cout << G << '\n';
    }
    
    return 0;
}
