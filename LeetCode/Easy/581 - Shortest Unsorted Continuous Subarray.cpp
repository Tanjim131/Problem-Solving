class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int minimum = numeric_limits<int>::max();
        int maximum = numeric_limits<int>::min();
        for(int i = 0 ; i < nums.size() - 1 ; ++i){
            if(nums[i] > nums[i + 1]){
                minimum = min(minimum, nums[i + 1]);
                maximum = max(maximum, nums[i]);
            }
        }
        if(minimum == numeric_limits<int>::max()) return 0; // already sorted
        int index1 = 0, index2 = nums.size() - 1;
        for(int i = 0 ; i < nums.size() ; ++i, ++index1){
            if(minimum < nums[i]){
                break;
            }
        }
        for(int i = nums.size() - 1 ; i >= 0 ; --i, --index2){
            if(maximum > nums[i]){
                break;
            }
        }
        return index2 - index1 + 1;
    }
};

/*

class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int minimum = numeric_limits<int>::max();
        int maximum = numeric_limits<int>::min();
        int fo = -1, lo = -1;
        for(int i = 0 ; i < nums.size() - 1 ; ++i){
            if(nums[i] > nums[i + 1]){
                if(fo == -1) fo = i;
                lo = i;
                minimum = min(minimum, nums[i + 1]);
                maximum = max(maximum, nums[i]);
            }
        }
        if(fo == -1) return 0; // already sorted
        int cmin = 0, cmax = 0;
        for(int i = fo ; i < nums.size() ; ++i){
            if(nums[i] == minimum) ++cmin;
        }
        for(int i = lo ; i >= 0 ; --i){
            if(nums[i] == maximum) ++cmax;
        }
        int index1 = 0, index2 = nums.size() - 1;
        for(int i = 0 ; i < nums.size() ; ++i){
            if(minimum >= nums[i]){
                ++index1;
            }
            if(maximum <= nums[i]){
                --index2;
            }
        }
        return (index2 + cmax) - (index1 - cmin) + 1;
    }
};

*/