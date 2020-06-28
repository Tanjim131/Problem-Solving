#include <iostream>

int main(int argc, char const *argv[])
{
    int T;
    std::cin >> T;
    while(T--){
        int n;
        std::cin >> n;
        if(n % 3 == 1){
            std::cout << "NO\n";
        } else{
            std::cout << "YES\n";
        }
    }
    return 0;
}
