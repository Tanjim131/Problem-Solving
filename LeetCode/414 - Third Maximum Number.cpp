
class Solution {
public:
    int thirdMax(vector<int>& nums) {
        int first_maximum = numeric_limits<int>::min(), second_maximum = numeric_limits<int>::min(), third_maximum = numeric_limits<int>::min();
        bool negative_min = false;

        for(int i = 0 ; i < nums.size() ; ++i){
            if(nums[i] == numeric_limits<int>::min()) negative_min = true;
            
            if(first_maximum < nums[i]){
                third_maximum = second_maximum;
                second_maximum = first_maximum;
                first_maximum = nums[i];
            } else if(second_maximum < nums[i] && nums[i] < first_maximum){
                third_maximum = second_maximum;
                second_maximum = nums[i];
            } else if(third_maximum < nums[i] && nums[i] < second_maximum){
                third_maximum = nums[i];
            }
        }

        if(third_maximum == second_maximum || third_maximum == numeric_limits<int>::min() && !negative_min) return first_maximum;
        return third_maximum;
    }
};
