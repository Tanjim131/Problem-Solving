#include <iostream>
#include <vector>

int find(const std::vector<int> &v, int val, int i = 0){
    if(i == v.size()) return -1;
    if(v[i] == val) return i;
    return find(v, val, i + 1);
}

int main(int argc, char const *argv[])
{
    std::vector <int> v{2, 9, 4, 7, 6};
    std::vector <int> queries{5, 9};
    for(int i = 0 ; i < queries.size() ; ++i){
        int index = find(v, queries[i]);
        if(index == -1){
            std::cout << "Not Found\n";
        } else{
            std::cout << index << '\n';
        }
    }
    return 0;
}
