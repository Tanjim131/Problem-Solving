#include <iostream>

int main(int argc, char const *argv[])
{
    int T; std::cin >> T;
    while(T--){
        int farmers; std::cin >> farmers;
        long long a,b,c,total = 0;
        for(int i = 0 ; i < farmers ; ++i){
            std::cin >> a >> b >> c;
            total += a * c;
        }
        std::cout << total << '\n';
    }
    return 0;
}