class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int m = -1, sm = -1; // max & second max
        for(int i = 0 ; i < nums.size() ; ++i){
            if(m < nums[i]){
                sm = m;
                m = nums[i];
            } else{
                sm = max(sm, nums[i]);
            }
        }
        return (m - 1) * (sm - 1);
    }
};