#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main()

{
    int n;
    while(cin >> n)
    {

        std::vector <int> ara(n), ara1(n, 0);

        for(int i = 0 ; i < n ; ++i){
            std::cin >> ara[i];
        }

        for(int i = 1 ; i < n ; i++){
            int diff = abs(ara[i] - ara[i - 1]);
            ara1[diff] = 1;
        }

        bool check = true;

        for(int i = 1 ; i <= n - 1 ; i++){
            if(ara1[i] == 0){
                check = false;
                break;
            }
        }

        if(check) printf("Jolly\n");

        else printf("Not jolly\n");
    }

    return 0;
}

