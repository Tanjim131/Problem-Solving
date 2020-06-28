#include <iostream>
#include <algorithm>

int main(int argc, char const *argv[])
{
    int T;
    std::cin >> T;
    while(T--){
        int n;
        std::cin >> n;
        int temp = n;
        int cnt_2 = 0, cnt_3 = 0;
        while(temp % 2 == 0){
            temp /= 2;
            ++cnt_2;
        }
        while(temp % 3 == 0){
            temp /= 3;
            ++cnt_3;
        }

        if(temp > 1){
            std::cout << "-1\n";
            continue;
        }

        int k = cnt_3 - cnt_2;
        if(k < 0){
            std::cout << "-1\n";
            continue;
        }
        
        std::cout << (k + cnt_3) << '\n';
    }
    return 0;
}
