class Solution {
public:
    string baseNeg2(int N) {
        string num;
        while(N != 0){
            int rem  = N % -2;
            N /= -2;
            if(rem < 0){
                ++N; // d = a - bc ; choose c such that d is non-negative and minimal, i.e., a - bc >= 0 or c >= a / b (b = -2 here)
                rem += 2;
            }
            num += rem + '0';
        }
        reverse(num.begin(), num.end());
        return num.empty() ? "0" : num;
    }
};