class Solution {
public:
    int maxProductPath(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        long long MOD = 1e9 + 7;
        vector<vector<long long>> max_p(m, vector<long long>(n));
        vector<vector<long long>> min_p(m, vector<long long>(n));
        max_p[0][0] = min_p[0][0] = grid[0][0];
        for (int i = 1; i < m; i++) {
            max_p[i][0] = min_p[i][0] = max_p[i-1][0] * grid[i][0];
        }
        for (int j = 1; j < n; j++) {
            max_p[0][j] = min_p[0][j] = max_p[0][j-1] * grid[0][j];
        }
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                long long val = grid[i][j];
                long long a = max_p[i-1][j] * val;
                long long b = min_p[i-1][j] * val;
                long long c = max_p[i][j-1] * val;
                long long d = min_p[i][j-1] * val;
                max_p[i][j] = max({a, b, c, d});
                min_p[i][j] = min({a, b, c, d});
            }
        }
        long long res = max_p[m-1][n-1];
        return (res < 0) ? -1 : res % MOD;
    }
};
