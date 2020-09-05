class Solution {
public:
    vector<int> decompressRLElist(vector<int>& nums) {
        vector <int> decompressed;
        decompressed.reserve(50000); // 50 vals each with 100 freq in the worst case
        // nums.size() is even, so nums.size() - 1 is odd
        // now, 2 * i + 1 < n => 2 * i < n - 1 => i < (n - 1) / 2
        // as n or nums.size() is even, (n - 1) / 2 will always be a fraction
        // so i <= (n - 1) / 2 will suffice
        // as nums.size() > 0, nums.size() - 1 will not overflow
        for(int i = 0 ; i <= (nums.size() - 1) / 2 ; ++i){
            int freq = nums[2 * i];
            int val = nums[2 * i + 1];
            while(freq--){
                decompressed.emplace_back(val);
            }
        }
        return decompressed;
    }
};