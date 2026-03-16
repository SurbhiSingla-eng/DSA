#include <vector>
#include <set>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> getBiggestThree(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        set<int> distinctSums;

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                // Every single cell is a rhombus of radius 0
                distinctSums.insert(grid[i][j]);
                if (distinctSums.size() > 3) distinctSums.erase(distinctSums.begin());

                // Try expanding the rhombus radius 'k'
                for (int k = 1; ; ++k) {
                    // Check if the 4 corners are within bounds
                    if (i - k < 0 || i + k >= m || j - k < 0 || j + k >= n) break;

                    int currentSum = 0;
                    
                    // Sum the 4 edges
                    // Top to Right, Right to Bottom, Bottom to Left, Left to Top
                    for (int x = 0; x < k; ++x) {
                        currentSum += grid[i - k + x][j + x]; // Top towards Right
                        currentSum += grid[i + x][j + k - x]; // Right towards Bottom
                        currentSum += grid[i + k - x][j - x]; // Bottom towards Left
                        currentSum += grid[i - x][j - k + x]; // Left towards Top
                    }

                    distinctSums.insert(currentSum);
                    if (distinctSums.size() > 3) {
                        distinctSums.erase(distinctSums.begin());
                    }
                }
            }
        }

        // Convert set to descending vector
        vector<int> result(distinctSums.rbegin(), distinctSums.rend());
        return result;
    }
};
