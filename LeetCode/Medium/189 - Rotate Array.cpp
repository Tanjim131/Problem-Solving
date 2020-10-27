
// O(n) time, O(n) memory
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        vector <int> modified{nums};
        for(int i = 0 ; i < nums.size() ; ++i){
            int new_pos = (i + k) % nums.size();
            modified[new_pos] = nums[i];
        }
        nums = modified;
    }
};

// O(n) time, O(1) memory

