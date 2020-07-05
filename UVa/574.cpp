#include <iostream>
#include <vector>
#include <set>

void printVector(const std::vector <int> &choices){
    for(int i = 0 ; i < choices.size() ; ++i){
        std::cout << choices[i];
        if(i != choices.size() - 1) std::cout << "+";
    }
    std::cout << '\n';
}

void sum(const std::vector <int> &nums, std::set <std::vector<int>> &s, int target_sum, int current_sum = 0, int index = 0, std::vector <int> current_choice = std::vector <int>()){
    if(current_sum > target_sum) return;

    if(current_sum == target_sum){
        if(s.find(current_choice) == s.end()){
            s.insert(current_choice);
        }
        return;
    }
    
    if(index == nums.size()) return;
    
    current_choice.emplace_back(nums[index]);
    sum(nums, s, target_sum, current_sum + nums[index], index + 1, current_choice);
    current_choice.pop_back();
    sum(nums, s, target_sum, current_sum, index + 1, current_choice);
}

int main(int argc, char const *argv[])
{
    int t,n;
    while(std::cin >> t >> n && n){
        std::vector <int> nums(n);
        for(int i = 0 ; i < n ; ++i) std::cin >> nums[i];
        std::set <std::vector<int>> s;
        sum(nums, s, t);
        std::cout << "Sums of " << t << ":\n";
        if(!s.size()){
            std::cout << "NONE\n";
        } else{
            for(auto it = s.rbegin() ; it != s.rend() ; ++it){
                printVector(*it);
            }
        }
    }
    return 0;
}
