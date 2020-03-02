class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        if(n == 0) return;

        int p = n+m-1, i = m-1, j = n-1;
        while(i >= 0 && j >= 0) {
            if(nums1[i] > nums2[j]) nums1[p] = nums1[i--];
            else nums1[p] = nums2[j--];
            p--;
        }
        while(j >= 0) {
            nums1[j] = nums2[j];
            j--;
        }
        return;
    }
};