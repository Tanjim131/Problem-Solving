#include <iostream>
#include <vector>
#include <numeric>
#include <cmath>
#include <algorithm>

class Constraint{
    public:
        int a,b,c;
};

void permuntations(std::vector <int> &group, const std::vector <Constraint> &constraints, int &counter, int index = 0){
    if(index == group.size()){
        // check the constraints, if all are matched, increase the counter
        bool satisfied = true;
        for(int i = 0 ; i < constraints.size() ; ++i){
            int index_a = std::find(group.begin(), group.end(), constraints[i].a) - group.begin();
            int index_b = std::find(group.begin(), group.end(), constraints[i].b) - group.begin();
            int dist = std::abs(index_a - index_b);
            if(constraints[i].c < 0){
                if(dist < constraints[i].c * -1) satisfied = false;
            } else{
                if(dist > constraints[i].c) satisfied = false;
            }
            if(!satisfied) break;
        }
        if(satisfied) ++counter;
        return;
    }
    permuntations(group, constraints, counter, index + 1);
    for(int i = index + 1 ; i < group.size() ; ++i){
        std::swap(group[index], group[i]);
        permuntations(group, constraints, counter, index + 1);
        std::swap(group[index], group[i]);
    }
}

int main(int argc, char const *argv[])
{
    int n,m;
    while(std::cin >> n >> m){
        if(!n && !m) break;
        std::vector <int> group(n);
        std::vector <Constraint> constraints(m);
        std::iota(group.begin(), group.end(), 0);
        for(int i = 0 ; i < m ; ++i){
            std::cin >> constraints[i].a >> constraints[i].b >> constraints[i].c;
        }
        int counter = 0;
        permuntations(group, constraints, counter);
        std::cout << counter << '\n';
    }
    return 0;
}
