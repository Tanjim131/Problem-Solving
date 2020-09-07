class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& A) {
        for(int i = 0 ; i < A.size() ; ++i){
            for(int j = 0 ; j < A[i].size() / 2 ; ++j){
                swap(A[i][j], A[i][A[i].size() - 1 - j]);
            }
        }
        for(int i = 0 ; i < A.size() ; ++i){
            for(int j = 0 ; j < A[i].size() ; ++j){
                A[i][j] ^= 1;
            }
        }
        return A;
    }
};