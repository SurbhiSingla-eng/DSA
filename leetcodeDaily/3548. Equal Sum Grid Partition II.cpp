#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

struct Bounds {
    int minR = 1e9, maxR = -1, minC = 1e9, maxC = -1;
};

class Solution {
public:
    bool canPartitionGrid(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        long long totalSum = 0;
        vector<long long> rowSums(m, 0), colSums(n, 0);
        unordered_map<int, Bounds> b;

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                int val = grid[i][j];
                totalSum += val;
                rowSums[i] += val;
                colSums[j] += val;
                b[val].minR = min(b[val].minR, i);
                b[val].maxR = max(b[val].maxR, i);
                b[val].minC = min(b[val].minC, j);
                b[val].maxC = max(b[val].maxC, j);
            }
        }

        // --- Horizontal Cuts ---
        long long topSum = 0;
        for (int i = 0; i < m - 1; ++i) {
            topSum += rowSums[i];
            long long botSum = totalSum - topSum;
            // Section 1: Rows [0, i], Cols [0, n-1]
            if (check(topSum, botSum, i + 1, n, grid, 0, i, 0, n - 1, b)) return true;
            // Section 2: Rows [i+1, m-1], Cols [0, n-1]
            if (check(botSum, topSum, m - 1 - i, n, grid, i + 1, m - 1, 0, n - 1, b)) return true;
        }

        // --- Vertical Cuts ---
        long long leftSum = 0;
        for (int j = 0; j < n - 1; ++j) {
            leftSum += colSums[j];
            long long rightSum = totalSum - leftSum;
            // Section 1: Rows [0, m-1], Cols [0, j]
            if (check(leftSum, rightSum, m, j + 1, grid, 0, m - 1, 0, j, b)) return true;
            // Section 2: Rows [0, m-1], Cols [j+1, n-1]
            if (check(rightSum, leftSum, m, n - 1 - j, grid, 0, m - 1, j + 1, n - 1, b)) return true;
        }

        return false;
    }

private:
    bool check(long long sA, long long sB, int h, int w, vector<vector<int>>& grid, 
               int r1, int r2, int c1, int c2, unordered_map<int, Bounds>& b) {
        if (sA == sB) return true;
        long long diff = sA - sB;
        if (diff <= 0 || diff > 1e9) return false; // Basic bounds check

        int d = (int)diff;
        if (b.find(d) == b.end()) return false;

        // Connectivity Rule:
        if (h == 1 && w == 1) return false; // Can't discount the only cell
        
        if (h == 1) return (grid[r1][c1] == d || grid[r1][c2] == d);
        if (w == 1) return (grid[r1][c1] == d || grid[r2][c1] == d);

        // 2D Block: Check if the value exists within these bounds
        // A value 'd' is in this rectangle if its min/max row/col are within [r1, r2] and [c1, c2].
        // However, we only need to know if AT LEAST ONE instance of 'd' is in the rectangle.
        // For a straight cut, a number is in the rectangle if its minR/maxR or minC/maxC overlap.
        return (b[d].minR <= r2 && b[d].maxR >= r1 && b[d].minC <= c2 && b[d].maxC >= c1);
    }
};
