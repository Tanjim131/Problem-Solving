class Solution {
public:
    int findNumbers(vector<int>& nums) {
        int counter = 0;
        for(int i = 0 ; i < nums.size() ; ++i){
            int digits = static_cast<int>(log10(nums[i])) + 1;
            counter += digits % 2 == 0;
        }
        return counter;
    }
};