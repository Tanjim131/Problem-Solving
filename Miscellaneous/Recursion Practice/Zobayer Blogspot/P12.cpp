#include <iostream>
#include <vector>
#include <algorithm>

std::pair<int,int> computeSecondMax(const std::vector <int> &v, int i = 0){
    if(i == v.size() - 1) return {v[i], -1};
    std::pair<int,int> ret = computeSecondMax(v, i + 1);
    if(v[i] == ret.first) return ret; // no new information
    if(v[i] > ret.first) return {v[i], ret.first}; // first and second max both updated
    return {ret.first, std::max(ret.second, v[i])}; // first is unchanged, second max may be updated
}

int main(int argc, char const *argv[])
{
    std::vector <int> v{7, 4, 19, 6, 2, 31, 8, 3};
    std::pair <int,int> ret = computeSecondMax(v);
    if(ret.second == -1){
        std::cout << "No second maximum number\n";
    } else{
        std::cout << ret.second << '\n';
    }
    return 0;
}
