class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int i = nums.size() - 1;
        while(i > 0 && nums[i - 1] >= nums[i]) --i;
        if(!i){
            // reverse and return
            int len = nums.size();
            for(int j = 0 ; j < len / 2 ; ++j){
                swap(nums[j], nums[len - 1 - j]);
            }
            return;
        }
        int j = nums.size() - 1;
        while(j > i && nums[i - 1] >= nums[j]) --j;
        swap(nums[i - 1], nums[j]);
        int len = nums.size() - i + 1;
        for(int k = 0 ; k < len / 2;  ++k){
            swap(nums[i + k], nums[nums.size() - 1 - k]);
        }
    }
};