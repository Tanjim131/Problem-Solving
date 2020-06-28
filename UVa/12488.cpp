#include <iostream>
#include <algorithm>
#include <vector>

int compute_overtakes(std::vector <int> &start, const std::vector <int> &finish){
    int overtakes = 0;
    for(int i = 0 ; i < finish.size() ; ++i){
        // find finish[i] in start
        int position_in_start = std::find(start.begin(), start.end(), finish[i]) - start.begin();
        // bring it to i-th position of start
        overtakes += (position_in_start - i);
        start.erase(start.begin() + position_in_start);
        start.insert(start.begin() + i, finish[i]);
    }
    return overtakes;
}

int main(int argc, char const *argv[])
{
    int N;
    while(std::cin >> N){
        std::vector <int> start(N), finish(N);
        for(int i = 0 ; i < N ; ++i) std::cin >> start[i];
        for(int i = 0 ; i < N ; ++i) std::cin >> finish[i];
        std::cout << compute_overtakes(start, finish) << '\n';
    }
    return 0;
}
