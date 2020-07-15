#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>
#include <iomanip>

// this function return a and a^3 such that a^3 <= n
std::pair<int,int> compute(double n, const std::vector <int> &perfect_cubes){
    int f = n; // same as floor as n is positive
    int a = std::lower_bound(perfect_cubes.begin(), perfect_cubes.end(), n) - perfect_cubes.begin();
    if(perfect_cubes[a] > f) --a;
    return {a, perfect_cubes[a]};
}

std::vector <int> generate_perfect_cubes(){
    std::vector <int> perfect_cubes(101);
    for(int i = 1 ; i <= 100 ; ++i){
        perfect_cubes[i] = i * i * i;
    }
    return perfect_cubes;
}

int main(int argc, char const *argv[])
{
    std::vector <int> perfect_cubes = generate_perfect_cubes();
    double n;
    while(std::cin >> n && n != 0.0){
        int a = 0, cube = 0;
        std::tie(a,cube) = compute(n, perfect_cubes);
        double dx = (n - cube) * a / (3.0 * cube);
        double cube_root = a + dx;
        std::cout << std::fixed << std::setprecision(4) << cube_root << '\n';
    }
    return 0;
}
