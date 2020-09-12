class Solution {
public:
    bool isPalindrome(string s) {
        // string trimmed;
        // for(auto c : s){
        //     if(isalnum(c)) {
        //         trimmed += ::tolower(c);
        //     }
        // }
        // //cout << trimmed << '\n';
        // for(int i = 0 ; i < trimmed.length() / 2 ; ++i){
        //     if(trimmed[i] != trimmed[trimmed.length() - 1 - i]) return false;
        // }
        // return true;
        int i = 0, j = s.length() - 1;
        while(i < j){
            if(!isalnum(s[i])){
                ++i;
                continue;
            }
            if(!isalnum(s[j])){
                --j;
                continue;
            }
            if(::tolower(s[i++]) != ::tolower(s[j--])){
                return false;
            }
        }
        return true;
    }
};