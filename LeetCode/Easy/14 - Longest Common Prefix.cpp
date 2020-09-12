class Solution {
public:
    bool ok(const vector <string> &strs, int length){
        string prefix = strs[0].substr(0, length);
        for(int i = 1 ; i < strs.size() ; ++i){
            string _prefix = strs[i].substr(0, length);
            if(prefix != _prefix) return false;
        }
        return true;
    }
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.empty()) return ""; // Have to be careful about corner cases
        int high = numeric_limits<int>::max();
        for(int i = 0 ; i < strs.size() ; ++i){
            high = min(high, static_cast<int>(strs[i].length()));
        }
        int low = 0, ans = -1;
        while(low <= high){
            int mid = (low + high) / 2;
            if(ok(strs, mid)){
                ans = mid;
                low = mid + 1;
            } else{
                high = mid - 1;
            }
        }
        return strs[0].substr(0, ans);
    }
};