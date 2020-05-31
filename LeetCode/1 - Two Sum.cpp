class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map <int, int> imap;
        vector <int> result;
        for(int i = 0 ; i < nums.size() ; ++i){
            auto it = imap.find(target - nums[i]);
            if(it != imap.end()){
                result.insert(result.end(), {it -> second, i});
                break;
            }
            imap[nums[i]] = i;
        }
        return result;
    }
};
