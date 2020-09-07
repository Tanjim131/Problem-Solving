class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.empty()) return 0;
        vector <int> count(256, 0);
        int start = 0, end = -1;
        int max_length = 1;
        while(end + 1 < s.length()){
            if(!count[s[++end]]){
                ++count[s[end]];
                max_length = max(max_length, end - start + 1);
            } else{
                --count[s[start++]];
                --end;
            }
        }
        return max_length;
    }
};