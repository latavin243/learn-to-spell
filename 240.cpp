class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        /*
         * Integers in each row are sorted in ascending from left to right.
         * Integers in each column are sorted in ascending from top to bottom.
         */
        if(matrix.size() == 0 || matrix[0].size() == 0) return false;

        int curCol = 0, preCol = 0, colLen = matrix[0].size();
        for (int i = 0; i < matrix.size(); i++) { // row
            bool fromSmall = false, fromLarge = false;
            while (matrix[i][curCol] < target) {
                if(curCol + 1 < colLen) {
                    fromSmall = true;
                    curCol++;
                }
                else break;
            }
            if(matrix[i][curCol] == target) return true;
            if(fromSmall) {
                curCol = min(0, curCol-1);
                continue;
            }

            while (matrix[i][curCol] > target) {
                if(curCol - 1 >= 0) {
                    fromLarge = true;
                    curCol--;
                }
                else break;
            }
            if(matrix[i][curCol] == target) return true;
            if(fromLarge) {
                curCol = max(curCol+1, colLen-1);
                continue;
            }
        }
        return false;
    }
};