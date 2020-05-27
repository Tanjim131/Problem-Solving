#include <iostream>
#include <algorithm>

int main(int argc, char const *argv[])
{
    int a,b;
    while(std::cin >> a >> b){
        if(a == -1 && b == -1) break;
        int clockwise = (b - a + 100) % 100;
        int counterclockwise = (a - b + 100) % 100;
        std::cout << std::min(clockwise, counterclockwise) << '\n';
    }
    return 0;
}
