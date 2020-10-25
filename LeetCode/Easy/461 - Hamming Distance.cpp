class Solution {
public:
    int hammingDistance(int x, int y) {
        int XOR = x ^ y;
        int count = 0;
        while(XOR != 0){
            count += XOR & 1;
            XOR >>= 1;
        }
        return count;
    }
};