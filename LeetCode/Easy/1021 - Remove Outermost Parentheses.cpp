class Solution {
public:
    string removeOuterParentheses(string S) {
        string modified; 
        modified.reserve(S.length());
        for(int i = 0, opened = 0, closed = 0 ; i < S.length() ; ++i){
            if(S[i] == '(') {
                if(opened++){ // discard leading parentheses
                    modified += S[i]; 
                }
            }
            else {
                ++closed;
                modified += S[i];
            }
            if(opened == closed){
                opened = closed = 0;
                modified.pop_back(); // discard trailing parentheses
            }
        }
        return modified;
    }
};