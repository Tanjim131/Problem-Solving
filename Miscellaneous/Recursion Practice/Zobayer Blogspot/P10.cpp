#include <iostream>

int computeLCM(int a, int b, int i = 1){
    if((a * i) % b == 0) return a * i;
    return computeLCM(a, b, i + 1);
}

int main(int argc, char const *argv[])
{
    int a = 1224, b = 2016; 
    if(a < b) std::swap(a,b);
    std::cout << computeLCM(a,b) << '\n';
    return 0;
}
