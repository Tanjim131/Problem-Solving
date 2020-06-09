#include <iostream>
#include <vector>
#include <set>

bool backtrack(const std::vector <int> &permutation, int output, int index = 1){
    if(index == permutation.size()){
        return output == 23;
    }
    
    bool plus = backtrack(permutation,  output + permutation[index], index + 1);
    bool minus = backtrack(permutation,  output - permutation[index], index + 1);
    bool mult = backtrack(permutation,  output * permutation[index], index + 1);

    return plus || minus || mult;
}

bool generate_permutations(std::vector<int> &nums, int index = 0, std::set<std::vector<int>> s = std::set<std::vector<int>>()){
    if(index == nums.size()){
        if(s.find(nums) == s.end()){
            s.insert(nums);
            return backtrack(nums, nums[0]);
        } 
    }
    bool ret = generate_permutations(nums, index + 1);
    if(ret) return true;
    for(int i = index + 1 ; i < nums.size() ; ++i){ 
        std::swap(nums[index], nums[i]);
        ret = generate_permutations(nums, index + 1);
        if(ret) break;
        std::swap(nums[index], nums[i]);
    }
    return ret;
}

int main(int argc, char const *argv[])
{
    std::vector <int> nums(5);
    while(true){
        bool allZero = true;
        for(int i = 0 ; i < 5 ; ++i){
            std::cin >> nums[i];
            if(nums[i]) allZero = false;
        }
        if(allZero) break;
        bool possible = generate_permutations(nums);
        if(possible){
            std::cout << "Possible\n";
        } else{
            std::cout << "Impossible\n";
        }
    }
    return 0;
}
