class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size() == 0) return 0;
        
        int index = 1, value = nums[0];
        for(int i = 0 ; i < nums.size() - 1 ; ++i){
            if(nums[i] == nums[i + 1]){
                index = i + 1;
                value = nums[index];
                break;
            } else{
                value = nums[index++];
            }
        }

        int k = index;
        while(k < nums.size()){
            while(k < nums.size() && nums[k] <= value) ++k;
            if(k == nums.size()) break;
            nums[index] = nums[k];
            value = nums[index++];
        }
        return index;
    }
};
