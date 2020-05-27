#include <iostream>

int main(int argc, char const *argv[])
{
    int n, k = 0;
    while(std::cin >> n && n){
        int eb = 0;
        for(int i = 0 ; i < n ; ++i){
            int x; std::cin >> x;
            if(x) ++eb;
            else --eb;
        }
        std::cout << "Case " << ++k << ": " << eb << '\n';
    }
    return 0;
}
