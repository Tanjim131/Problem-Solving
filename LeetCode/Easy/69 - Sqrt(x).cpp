class Solution {
public:
    int mySqrt(int x) {
        double low = 0.0, high = x;
        for(int i = 0 ; i < 100 ; ++i){
            double mid = (low + high) / 2.0;
            if(mid * mid <= x){
                low = mid;
            } else{
                high = mid;
            }
        }
        return low;
    }
};