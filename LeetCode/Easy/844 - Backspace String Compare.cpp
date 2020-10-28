
// O(N) Time, O(N) Space
class Solution {
public:
    bool backspaceCompare(string S, string T) {
        stack <char> s1;
        for(int i = 0 ; i < S.length() ; ++i){
            if(S[i] == '#' && !s1.empty()){
                s1.pop();
            } else if(S[i] != '#') {
                s1.push(S[i]);
            }
        }
        stack <char> s2;
        for(int i = 0 ; i < T.length() ; ++i){
            if(T[i] == '#' && !s2.empty()){
                s2.pop();
            } else if(T[i] != '#'){
                s2.push(T[i]);
            }
        }
        return s1 == s2;
    }
};

/*********************************************************************************************/

class Solution {
public:
    bool backspaceCompare(string S, string T) {
        int sl = S.length();
        for(int i = 0 ; i < sl ; ++i){
            if(S[i] != '#'){
                S.push_back(S[i]);
            } else if(S.length() > sl) {
                S.pop_back();
            }
        }
        int tl = T.length();
        for(int i = 0 ; i < tl ; ++i){
            if(T[i] != '#'){
                T.push_back(T[i]);
            } else if(T.length() > tl) {
                T.pop_back();
            }
        }
        if(S.length() - sl != T.length() - tl) return false;
        for(int i = sl, j = tl ; i < S.length() ; ++i, ++j){
            if(S[i] != T[j]) return false;
        }
        return true;
    }
};

// O(N) Time, O(1) Space

