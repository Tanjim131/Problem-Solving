// Carefully read the problem statement and carefully examine the sample test cases!!

class Solution {
public:
    bool buddyStrings(string A, string B) {
        if(A.length() != B.length()) return false;
        vector <int> count(26, 0);
        int unique = 0;
        for(int i = 0 ; i < A.length() ; ++i){
            if(!count[A[i] - 'a']){
                ++unique;
            }
            ++count[A[i] - 'a'];
        }
        if(A == B){
            if(unique == A.length()) return false;
            return true;
        } 
        int swaps = 0;
        for(int i = 0 ; i < A.length() ; ++i){
            if(A[i] == B[i]) continue;
            if(swaps == 1) return false;
            bool found = false;
            for(int j = i + 1 ; j < A.length() ; ++j){
                if(A[j] == B[i]){
                    swap(A[i], A[j]);
                    ++swaps;
                    found = true;
                    break;
                }
            }
            if(!found) return false;
        }
        return true;
    }
};