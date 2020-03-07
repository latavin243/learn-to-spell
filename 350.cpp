class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        vector<int> res;
        if (nums1.size() == 0 || nums2.size() == 0) return res;
        unordered_map<int,int> m;
        for (int n : nums1) m[n]++;
        for (int n : nums2) {
            if (m[n]) {
                res.push_back(n);
                m[n]--;
            }
        }
        return res;
    }
};