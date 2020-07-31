#include <iostream>
#include <vector>
#include <algorithm>

int main(int argc, char const *argv[])
{
    int N,L;
    std::cin >> N >> L;
    std::vector <std::string> strings(N);
    for(int i = 0 ; i < N ; ++i){
        std::cin >> strings[i];
    }
    std::sort(strings.begin(), strings.end());
    for(int i = 0 ; i < N ; ++i){
        std::cout << strings[i];
    }
    return 0;
}
