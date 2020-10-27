class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int closest = 0;
        int min_difference = numeric_limits<int>::max();
        for(int i = 0 ; i < nums.size() ; ++i){
            int j = i + 1, k = nums.size() - 1;
            while(j < k){
                int sum = nums[i] + nums[j] + nums[k];
                int difference = abs(sum - target);
                if(min_difference > difference){
                    min_difference = difference;
                    closest = sum;
                }
                if(sum == target){
                    break;
                } else if(sum < target){
                    ++j;
                } else{
                    --k;
                }
            }
        }
        return closest;
    }
};