class Solution {
public:
    bool judgeSquareSum(int c) {
        // for(int b = 0 ; c >= 1LL * b * b ; ++b){
        //     int rhs = c - b * b;
        //     double sqrtA = sqrt(rhs);
        //     int f = static_cast <int>(floor(sqrtA));
        //     int c = static_cast <int>(ceil(sqrtA));
        //     if(f == c) return true;
        // }
        // return false;
        
        // if there is a solution then a <= sqrt(c) && b <= sqrt(c)
        // because if a > sqrt(c) || b > sqrt(c), then a^2 + b^2 > c
        
        int sqrtN = sqrt(c);
        int l = 0, r = sqrtN;
        while(l <= r){
            int lhs = l * l;
            int rhs = c - r * r;
            if(lhs == rhs) return true;
            if(lhs < rhs) ++l;
            else --r;
        }
        return false;
    }
};