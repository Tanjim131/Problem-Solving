class Solution {
public:
    int bs(const vector<int> &nums, int target){
        int lo = 0 , hi = nums.size() - 1, mid = -1;
        bool flag = false;
        while(lo <= hi){
            mid = (lo + hi) / 2;
            if(nums[mid] == target){
                flag = true;
                break;
            }
            else if(nums[mid] > target) --hi;
            else ++lo;
        }   
    
        if(flag) return mid;
        if(lo == nums.size() - 1 && target > nums[lo]) return lo + 1;
        return lo;
    }

    int searchInsert(vector<int>& nums, int target) {
        return bs(nums, target);
    }
};