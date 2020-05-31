#include <iostream>
#include <vector>

int main(int argc, char const *argv[])
{
    int n, k = 0;
    while(std::cin >> n){
        if(!n) break;
        if(k > 0) std::cout << '\n';
        std::vector <int> subset(n);
        for(int i = 0 ; i < n ; ++i){   
            std::cin >> subset[i];
        }
        for(int i = 0 ; i <= n - 6 ; ++i){
            for(int j = i + 1 ; j <= n - 5 ; ++j){
                for(int k = j + 1 ; k <= n - 4 ; ++k){
                    for(int l = k + 1 ; l <= n - 3 ; ++l){
                        for(int m = l + 1 ; m <= n - 2 ; ++m){
                            for(int p = m + 1 ; p <= n - 1 ; ++p){
                                std::cout << subset[i] << " " << subset[j] << " " << subset[k] << " " << subset[l] << " " << subset[m] << " " << subset[p] << '\n';
                            }
                        }
                    }
                }
            }
        }
        ++k;
    }
    return 0;
}
