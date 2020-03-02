class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        /*
         * Integers in each row are sorted in ascending from left to right.
         * Integers in each column are sorted in ascending from top to bottom.
         */
        if(matrix.size() == 0 || matrix[0].size() == 0) return false;

        int n = matrix.size(), m = matrix[0].size(), i = 0, j = m-1;
        while(i < n && j >= 0) {
            if(matrix[i][j] == target) return true;
            else if(matrix[i][j] > target) j--;
            else i++;
        }
        return false;
    }
};