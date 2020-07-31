#include <iostream>

int main(int argc, char const *argv[])
{
    int T;
    std::cin >> T;
    while(T--){
        int x,y,n;
        std::cin >> x >> y >> n;
        std::div_t result = std::div(n - y, x);
        int answer = n;
        if(result.rem){
            answer -= result.rem;
        }
        std::cout << answer << '\n';
    }
    return 0;
}
