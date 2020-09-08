class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t reversed = 0;
        for(int i = 0 ; i < 32 ; ++i){
            reversed = (reversed << 1) | ((n & (1 << i)) >> i);
        }
        return reversed;
    }
};

/*
uint32_t reverseBits(uint32_t n) {
    uint32_t reversed = 0;
    for(int i = 0 ; i < 32 ; ++i){
        reversed = (reversed << 1) | (n & 1);
        n >>= 1;
    }
    return reversed;
}
*/
