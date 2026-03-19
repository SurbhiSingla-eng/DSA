class Solution {
public:
    int numberOfSubmatrices(vector<vector<char>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        vector<vector<int>> countX(rows + 1, vector<int>(cols + 1, 0));
        vector<vector<int>> countY(rows + 1, vector<int>(cols + 1, 0));
        int validSubmatrices = 0;
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                countX[i + 1][j + 1] = countX[i][j + 1] + countX[i + 1][j] - countX[i][j] + (grid[i][j] == 'X' ? 1 : 0);
                countY[i + 1][j + 1] = countY[i][j + 1] + countY[i + 1][j] - countY[i][j] + (grid[i][j] == 'Y' ? 1 : 0);
                if (countX[i + 1][j + 1] == countY[i + 1][j + 1] && countX[i + 1][j + 1] > 0) {
                    validSubmatrices++;
                }
            }
        }
        return validSubmatrices;
    }
};
