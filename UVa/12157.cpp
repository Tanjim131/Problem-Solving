#include <iostream>

int main(int argc, char const *argv[])
{
    int T, k = 0;
    std::cin >> T;
    while(T--){
        int N;
        std::cin >> N;
        int mile = 0, juice = 0;
        for(int i = 0 ; i < N ; ++i){
            int duration;
            std::cin >> duration;
            mile += ((duration / 30) + 1) * 10;
            juice += ((duration / 60) + 1) * 15;
        }
        std::cout << "Case " << ++k << ": ";
        int answer = std::min(mile, juice);
        if(answer == mile && answer == juice){
            std::cout << "Mile Juice ";
        } else if(answer == mile){
            std::cout << "Mile ";
        } else{
            std::cout << "Juice ";
        }
        std::cout << answer << '\n';
    }
    return 0;
}
