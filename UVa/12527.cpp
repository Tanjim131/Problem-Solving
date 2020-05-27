#include <iostream>
#include <vector>

inline bool ok(int n){
    std::vector <int> v(10,0);
    while(n){
        int mod = n % 10;
        if(v[mod]) return false;
        else ++v[mod];
        n /= 10;
    }
    return true;
}

int main(int argc, char const *argv[])
{
    int N,M;
    while(std::cin >> N >> M){
        int counter = 0;
        for(int i = N ; i <= M ; ++i){
            if(ok(i)) ++counter;
        }
        std::cout << counter << '\n';
    }
    return 0;
}
