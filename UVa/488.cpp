#include <iostream>

int main(int argc, char const *argv[])
{
    int T; std::cin >> T;
    while(T--){
        int amplitude, frequency;
        std::cin >> amplitude >> frequency;
        for(int i = 0 ; i < frequency ; ++i){
            int value_to_print = 1;
            for(int j = 1 ; j <= (amplitude << 1) - 1 ; ++j){
                for(int k = 0 ; k < value_to_print ; ++k){
                    std::cout << value_to_print;
                }
                std::cout << '\n';
                if(j < amplitude) ++value_to_print;
                else --value_to_print;
            }
            if(i != frequency - 1) std::cout << '\n';
        }
        if(T) std::cout << '\n';
    }
    return 0;
}
