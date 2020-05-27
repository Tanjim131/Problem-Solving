#include <iostream>
#include <unordered_set>

int main(int argc, char const *argv[])
{
    int T, k = 0; std::cin >> T;
    while(T--){
        int n; std::cin >> n;
        std::unordered_set <int> us;
        for(int i = 0 ; i < n ; ++i){
            int y1,y2; std::cin >> y1 >> y2;
            us.insert(y1 - y2);
        }
        if(us.size() > 1){
            std::cout << "no\n";
        } else{
            std::cout << "yes\n";
        }
        if(T) std::cout << '\n';
    }
    return 0;
}
