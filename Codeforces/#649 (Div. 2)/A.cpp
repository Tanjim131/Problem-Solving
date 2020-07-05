#include <iostream>
#include <vector>
#include <algorithm>

int main(int argc, char const *argv[])
{
    int T;
    std::cin >> T;
    while(T--){
        int n, x;
        std::cin >> n >> x;
        std::vector <int> a(n);
        int sum = 0;
        for(int i = 0 ; i < n ; ++i) {
            std::cin >> a[i];
            sum += a[i];
        }
        int max_length = a.size();
        int i = 0, j = a.size() - 1;
        while(i < j){
            int left = a[i];
            int right = a[j];
            if((sum - left) % x){
                --max_length;
                break;
            }
            if((sum - right) % x){
                --max_length;
                break;
            }
            
        }
        std::cout << max_length << '\n';
    }
    return 0;
}
