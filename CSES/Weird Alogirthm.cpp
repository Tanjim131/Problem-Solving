#include <iostream>

int main(int argc, char const *argv[])
{
    long long n;
    std::cin >> n;
    while(n != 1){
        std::cout << n << " ";
        if(n % 2 == 0){
            n /= 2;
        } else{
            n = 3 * n + 1;
        }
    }
    std::cout << "1\n";
    return 0;
}
