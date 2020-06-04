#include <iostream>
#include <vector>
#include <cstdlib>

class Pair{
    public:
        int x,y;
        Pair(int _x, int _y) : x(_x), y(_y){}
};

void printSolutions(int k){
    int min_y = k + 1;
    int max_y = 2 * k;
    int range = max_y - min_y + 1;
    std::vector <Pair> values;
    values.reserve(range);

    for(int i = min_y ; i <= max_y ; ++i){
        div_t result = div(i * k, i - k);
        if(!result.rem){
            values.emplace_back(Pair(result.quot, i));
        }
    }

    std::cout << values.size() << '\n';
    for(const Pair &p : values){
        std::cout << "1/" << k << " = 1/" << p.x << " + 1/" << p.y << '\n'; 
    }
}

int main(int argc, char const *argv[])
{
    int k;
    while(std::cin >> k){
        printSolutions(k);
    }
    return 0;
}
