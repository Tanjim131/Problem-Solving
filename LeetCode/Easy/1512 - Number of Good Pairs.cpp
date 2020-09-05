class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        vector <int> count(100 + 1, 0);
        int answer = 0;
        for(int i = 0 ; i < nums.size() ; ++i){
            answer += count[nums[i]]++;
        }
        // int answer = 0;
        // for(int i = 0 ; i < count.size() ; ++i){
        //     if(count[i] < 2) continue;
        //     answer += count[i] * (count[i] - 1) / 2;
        // }
        return answer;
    }
};