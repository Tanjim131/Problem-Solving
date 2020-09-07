/*
*   Initial mistake: just counting the number of unordered pairs!
*   - if there exists an index i such that nums[i] > nums[i + 1]
*   - you can do either nums[i] = nums[i + 1] or nums[i + 1] = nums[i]
*   - then check if the array is non-decreasing
*   - if it isn't, then return false (because you can do at most one operation)
*   - otherwise return true
*/

class Solution {
public:
    bool checkPossibility(vector<int>& nums){
        int index = -1;
        for(int i = 0 ; i < nums.size() - 1 ; ++i){
            if(nums[i] > nums[i + 1]){
                index = i;
                break;
            }
        }
        if(index == -1) return true;
        bool p = true, q = true;
        int a = nums[index], b = nums[index + 1];
        {
            nums[index] = b;
            for(int i = 0 ; i < nums.size() - 1 ; ++i){
                if(nums[i] > nums[i + 1]){
                    p = false;
                    break;
                }
            }
        }
        if(p) return true;
        {
            nums[index] = nums[index + 1] = a;
            for(int i = 0 ; i < nums.size() - 1 ; ++i){
                if(nums[i] > nums[i + 1]){
                    q = false;
                    break;
                }
            }
        }
        if(q) return true;
        return false;
    }
};