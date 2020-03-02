class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        /*
         * Integers in each row are sorted from left to right.
         * The first integer of each row is greater than the last integer of the previous row.
         */
        int n = matrix.size();
        if (n == 0) return false;
        int m = matrix[0].size();
        if (m == 0) return false;

        int i = 0, j = 0;
        while(i < n && matrix[i][m-1] < target) i++;
        if(i >= n) return false;
        while(j < m && matrix[i][j] < target) j++;
        if(j >= m) return false;
        return matrix[i][j] == target;
    }
};