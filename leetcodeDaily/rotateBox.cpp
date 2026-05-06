class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& boxGrid) {
        int m = boxGrid.size();
        int n = boxGrid[0].size();
        vector<vector<char>> rotated(n, vector<char>(m));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                rotated[j][m - 1 - i] = boxGrid[i][j];
            }
        }
        for (int col = 0; col < m; col++) {
            for (int row = n - 2; row >= 0; row--) {
                if (rotated[row][col] == '#') {
                    int curr = row;
                    while (curr + 1 < n &&
                           rotated[curr + 1][col] == '.') {
                        swap(rotated[curr][col],
                             rotated[curr + 1][col]);
                        curr++;
                    }
                }
            }
        }
        return rotated;
    }
};
