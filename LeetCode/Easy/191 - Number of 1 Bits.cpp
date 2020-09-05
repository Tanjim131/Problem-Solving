class Solution {
public:
    int hammingWeight(uint32_t n) {
        int counter = 0;
        while(n){
            if(n & 1) ++counter;
            n >>= 1;
        }
        return counter; 
    }
};