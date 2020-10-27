class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        set <vector<int>> unique_triplets;
        for(int i = 0 ; i < nums.size() ; ++i){
            int j = i + 1, k = nums.size() - 1;
            while(j < k){
                if(nums[i] + nums[j] + nums[k] == 0){
                    vector <int> triplet{nums[i], nums[j], nums[k]};
                    if(unique_triplets.find(triplet) == unique_triplets.end()){
                        unique_triplets.insert(triplet);
                    }
                    ++j, --k;
                } else if(nums[i] + nums[j] + nums[k] < 0){
                    ++j;
                } else{
                    --k;
                }
            }
        }
        return vector<vector<int>>(unique_triplets.begin(), unique_triplets.end());
    }
};