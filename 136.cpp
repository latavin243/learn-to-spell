class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_set<int> s;
        for (int n : nums) {
            if(s.find(n) == s.end()) s.insert(n);
            else s.erase(s.find(n));
        }
        return *s.begin();
    }
};