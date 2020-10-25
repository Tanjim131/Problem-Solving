class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int index = m + n - 1;
        int nums1_last = m - 1, nums2_last = n - 1;
        while(index >= 0){
            if(nums1_last >= 0 && nums2_last >= 0){
                if(nums1[nums1_last] >= nums2[nums2_last]){
                    nums1[index--] = nums1[nums1_last--];
                } else{
                    nums1[index--] = nums2[nums2_last--];
                }
            } else if(nums1_last >= 0){
                nums1[index--] = nums1[nums1_last--];
            } else{
                nums1[index--] = nums2[nums2_last--];
            }
        }
    }
};