class Solution {
public:
    bool validMountainArray(vector<int>& A) {
        int i;
        for(i = 0 ; i + 1 < A.size()  ; ++i){
            if(A[i] == A[i + 1]) return false;
            if(A[i] > A[i + 1]) break;
        }
        if(i == 0 || i + 1 == A.size()) return false; // strictly increasing or decreasing array
        for(int j = i ; j + 1 < A.size() ; ++j){
            if(A[j] <= A[j + 1]) return false;
        }
        return true;
    }
};