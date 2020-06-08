#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

inline bool isValid(const std::vector<int> &months_values, int current_month){
    return std::accumulate(months_values.begin() + current_month - 5, months_values.begin() + current_month, 0) < 0;
}

void backtrack(std::vector<int> &months_values, int surplus, int deficit, int &answer, int current_month = 0,  int current_sum = 0){
    if(current_month >= 5){
        // check if the constraint is respected
        if(!isValid(months_values, current_month)) return;
    }

    if(current_month == months_values.size()){
        // found the best solution 
        answer = std::max(answer, current_sum);
        return;
    }  

    if(answer == std::numeric_limits<int>::min()){ // proceed only if you haven't found any answer yet
        months_values[current_month] = surplus;
        backtrack(months_values, surplus, deficit, answer, current_month + 1, current_sum + surplus);

        months_values[current_month] = -deficit;
        backtrack(months_values, surplus, deficit, answer, current_month + 1, current_sum - deficit);
    }  
}

int main(int argc, char const *argv[])
{
    std::vector<int> months_values(12,0);
    int surplus,deficit;
    while(std::cin >> surplus >> deficit){
        int answer = std::numeric_limits<int>::min();
        backtrack(months_values, surplus, deficit, answer);
        if(answer < 0){
            std::cout << "Deficit\n";
        } else{
            std::cout << answer << '\n';
        }
    }
    return 0;
}