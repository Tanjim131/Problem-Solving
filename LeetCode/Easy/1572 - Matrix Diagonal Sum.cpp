class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        int sum = 0;
        for(int i = 0, j = 0 ; i < mat.size() ; ++i, ++j){
            int ltr = j, rtl = mat.size() - 1 - j;
            sum += mat[i][ltr];
            if(ltr != rtl) sum += mat[i][rtl];
        }
        return sum;
    }
};