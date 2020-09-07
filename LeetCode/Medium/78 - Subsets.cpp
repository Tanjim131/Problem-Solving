class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int ns = 1 << nums.size();
        vector <vector<int>> subsets(ns);
        for(int i = 0 ; i < ns ; ++i) {
            subsets[i].reserve(nums.size()); 
        }
        for(int i = 0 ; i < ns ; ++i){
            for(int j = 0 ; j < nums.size() ; ++j){
                if(i & (1 << j)){
                    subsets[i].emplace_back(nums[j]);
                }
            }
        }
        return subsets;
    }
};