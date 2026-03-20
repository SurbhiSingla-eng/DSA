#include <vector>
#include <set>
#include <algorithm>
#include <climits>
using namespace std;
class Solution {
public:
    vector<vector<int>> minAbsDiff(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();
        int resM = m - k + 1;
        int resN = n - k + 1;
        vector<vector<int>> ans(resM, vector<int>(resN));
        for (int i = 0; i < resM; ++i) {
            for (int j = 0; j < resN; ++j) {
                set<int> distinctElements;
                for (int r = i; r < i + k; ++r) {
                    for (int c = j; c < j + k; ++c) {
                        distinctElements.insert(grid[r][c]);
                    }
                }
                if (distinctElements.size() <= 1) {
                    ans[i][j] = 0;
                } else {
                    int minDiff = INT_MAX;
                    auto it = distinctElements.begin();
                    int prev = *it;
                    ++it;
                    while (it != distinctElements.end()) {
                        minDiff = min(minDiff, *it - prev);
                        prev = *it;
                        ++it;
                    }
                    ans[i][j] = minDiff;
                }
            }
        }
        return ans;
    }
};
