class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        // O(nlogn) solution
        // vector <int> sorted{nums};
        // sort(sorted.begin(), sorted.end());
        // vector <int> answer(nums.size(), 0);
        // for(int i = 0 ; i < nums.size() ; ++i){
        //     int count = lower_bound(sorted.begin(), sorted.end(), nums[i]) - sorted.begin();
        //     answer[i] = count;
        // }
        // return answer;
        
        // O(n) solution
        vector <int> count(100 + 1, 0);
        for(int i = 0 ; i < nums.size() ; ++i){
            ++count[nums[i]];
        }
        for(int i = 1 ; i < count.size() ; ++i){
            count[i] += count[i - 1];
        }
        vector <int> answer(nums.size(), 0);
        for(int i = 0 ; i < nums.size() ; ++i){
            if(nums[i] == 0) continue;
            answer[i] = count[nums[i] - 1];
        }
        return answer;
    }
};