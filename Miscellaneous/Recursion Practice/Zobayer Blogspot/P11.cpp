#include <iostream>
#include <vector>
#include <algorithm>

int computeMax(const std::vector <int> &v, int i = 0){
    if(i == v.size() - 1) return v[i];
    return std::max(v[i], computeMax(v, i + 1));
}

int computeMaxDC(const std::vector <int> &v, int i, int j){
    if(i == j) return v[i];
    int mid = (i + j) / 2;
    return std::max(computeMaxDC(v, i, mid), computeMaxDC(v, i + 1, j));
}

int main(int argc, char const *argv[])
{
    std::vector <int> v{7, 4, 9, 6, 2, 31, 8, 3, 19};
    std::cout << computeMaxDC(v, 0, v.size() - 1) << '\n';
    return 0;
}
