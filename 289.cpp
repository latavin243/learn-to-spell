class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        /*
         * Any live cell with fewer than two live neighbors dies, as if caused by under-population.
         * Any live cell with two or three live neighbors lives on to the next generation.
         * Any live cell with more than three live neighbors dies, as if by over-population..
         * Any dead cell with exactly three live neighbors becomes a live cell, as if by reproduction.
         */
        int m = board.size();
        if (!m) return;
        int n = board[0].size();
        if (!n) return;

        vector<vector<int>> neighborMatrix(m, vector<int>(n, 0));
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                neighborMatrix[i][j] = countNeighbors(board, i, j, m, n);

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                int neighbors = neighborMatrix[i][j];
                if (board[i][j] == 1 && (neighbors < 2 || neighbors > 3)) board[i][j] = 0;
                else if (board[i][j] == 0 && neighbors == 3) board[i][j] = 1;
            }
        }
        return;
    }

private:
    int countNeighbors(vector<vector<int>>& board, int row, int col, int rowMax, int colMax) {
        int res = 0;
        for (int i = row-1; i <= row+1; i++) {
            if (i <= 0 || i >= rowMax) continue;
            for (int j = col-1; j <= col+1; j++) {
                if (j <= 0 || j >= colMax) continue;
                else if (i == row && j == col) continue;
                else res += board[i][j];
            }
        }
        return res;
    }
};