class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        unordered_set <int> unique; 
        unique.reserve(nums.size());
        vector <int> duplicate;
        duplicate.reserve(nums.size());
        for(int i = 0 ; i < nums.size() ; ++i){
            if(unique.find(nums[i]) == unique.end()){
                unique.insert(nums[i]);
            } else{
                duplicate.emplace_back(nums[i]);
            }
        }
        return duplicate;
    }
};