class Solution {
public:
    vector<vector<string>> ans;
    bool isValid(int r, int c, int n, vector<string>& str) {
        // Check same column
        for (int i = 0; i < r; i++) {
            if (str[i][c] == 'Q')
                return false;
        }
        // Check upper left diagonal
        int i = r - 1;
        int j = c - 1;
        while (i >= 0 && j >= 0) {
            if (str[i][j] == 'Q')
                return false;
            i--;
            j--;
        }
        // Check upper right diagonal
        i = r - 1;
        j = c + 1;
        while (i >= 0 && j < n) {
            if (str[i][j] == 'Q')
                return false;
            i--;
            j++;
        }
        return true;
    }
    void solve(int r, int n, vector<string>& str) {
        if (r == n) {
            ans.push_back(str);
            return;
        }
        // traversing columns
        for (int c = 0; c < n; c++) {
            if (isValid(r, c, n, str)) {
                str[r][c] = 'Q';
                solve(r + 1, n, str);
                // backtracking
                str[r][c] = '.';
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<string> str(n, string(n, '.'));
        solve(0, n, str);
        return ans;
    }
};
