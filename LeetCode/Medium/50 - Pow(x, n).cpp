class Solution {
public:
    double myPow(double x, int n) {
        double ans = 1.0;
        bool negative = false;
        long long nn = n;
        if(nn < 0) {
            nn *= -1; 
            negative = true;
        }
        while(nn != 0){
            if(nn % 2 == 1){
                ans *= x;
            }
            x *= x;
            nn /= 2;
        }
        return negative ? 1.0 / ans : ans;
    }
};