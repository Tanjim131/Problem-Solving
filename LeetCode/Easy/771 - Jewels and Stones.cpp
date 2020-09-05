class Solution {
public:
    int numJewelsInStones(string J, string S) {
        vector <bool> track(52, false);
        for(int i = 0 ; i < J.length() ; ++i){
            if(J[i] >= 'a' && J[i] <= 'z'){
                track[J[i] - 'a'] = true;
            } else{
                track[J[i] - 'A' + 26] = true;
            }
        }
        int count = 0;
        for(int i = 0 ; i < S.length() ; ++i){
            if(S[i] >= 'a' && S[i] <= 'z'){
                if(track[S[i] - 'a']) ++count;
            } else{
                if(track[S[i] - 'A' + 26]) ++count;
            }
        }
        return count;
    }
};