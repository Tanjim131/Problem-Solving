class Solution {
public:
    int reverse(int x) {
        int rev = 0, check = 0;
        while(x){
            if(abs(rev) > INT_MAX / 10){
                return 0;
            }
            rev = rev * 10 + x % 10;
            x /= 10;
        }
        return rev;
    }
};