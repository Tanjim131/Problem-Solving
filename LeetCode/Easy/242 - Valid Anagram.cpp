class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.length() != t.length()) return false;
        vector <int> sc(26, 0), tc(26, 0);
        for(int i = 0 ; i < s.length() ; ++i){
            ++sc[s[i] - 'a'];
            ++tc[t[i] - 'a'];
        }
        for(int i = 0 ; i < 26 ; ++i){
            if(sc[i] != tc[i]) return false;
        }
        return true;
    }
};