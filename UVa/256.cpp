#include <iostream>
#include <vector>
#include <tuple>
#include <ext/numeric>
#include <unordered_map>
#include <iomanip>

inline bool check(int num, int power){
    int first = num / power;
    int second = num % power;
    int squared = (first + second) * (first + second);
    return squared == num;
}

std::vector<std::vector<int>> precalculate(const std::tuple<int,int,int,int> &t){
    int a,b,c,d;
    std::tie(a,b,c,d) = t;

    std::vector<std::vector<int>> table(4);

    int len_a = __gnu_cxx::power(10, a);
    int power_a = __gnu_cxx::power(10, a >> 1);
    for(int i = 0 ; i < len_a ; ++i){
        if(check(i, power_a)){
            table[0].emplace_back(i);
        }
    }

    int len_b = __gnu_cxx::power(10, b);
    int power_b = __gnu_cxx::power(10, b >> 1);
    for(int i = 0 ; i < len_b ; ++i){
        if(check(i, power_b)){
            table[1].emplace_back(i);
        }
    }
    
    int len_c = __gnu_cxx::power(10, c);
    int power_c = __gnu_cxx::power(10, c >> 1);
    for(int i = 0 ; i < len_c ; ++i){
        if(check(i, power_c)){
            table[2].emplace_back(i);
        }
    }
    
    int len_d = __gnu_cxx::power(10, d);
    int power_d = __gnu_cxx::power(10, d >> 1);
    for(int i = 0 ; i < len_d ; ++i){
        if(check(i, power_d)){
            table[3].emplace_back(i);
        }
    }

    return table;
}

int main(int argc, char const *argv[])
{
    std::vector<std::vector<int>> table = precalculate({2,4,6,8});
    std::unordered_map <int,int> ump = {
        {2, 0},
        {4, 1},
        {6, 2},
        {8, 3}
    };
    int n;
    while(std::cin >> n){
        int index = ump[n];
        for(int i = 0 ; i < table[index].size() ; ++i){
            std::cout << std::setfill('0') << std::setw(n) << table[index][i] << '\n';
        }
    } 
    return 0;
}
