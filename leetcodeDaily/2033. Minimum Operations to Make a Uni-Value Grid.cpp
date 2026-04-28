// class Solution {
// public:
//     int minOperations(vector<vector<int>>& grid, int x) {
//         int m = grid.size();
//         int n = grid[0].size();
//         int ans = INT_MAX;
//         for (int ti = 0; ti < m; ti++){
//             for (int tj = 0; tj < n; tj++){
//                 int target = grid[ti][tj];
//                 int count = 0;
//                 bool possible = true;
//                 for (int i = 0; i < m; i++){
//                     for (int j = 0; j < n; j++){
//                         int diff = abs(grid[i][j] - target);
//                         if (diff % x != 0){
//                             possible = false;
//                             break;
//                         }
//                         count += diff / x;
//                     }
//                     if (!possible) break;
//                 }
//                 if (possible){
//                     if (count < ans){
//                         ans = count;
//                     }
//                 }
//             }
//         }
//         if (ans == INT_MAX) {
//             return -1;
//         } else {
//             return ans;
//         }
//     }
// };

class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        vector<int> arr;
        for (auto &row : grid) {
            for (auto val : row) {
                arr.push_back(val);
            }
        }
        for (int i = 1; i < arr.size(); i++) {
            if ((arr[i] - arr[0]) % x != 0) {
                return -1;
            }
        }
        sort(arr.begin(), arr.end());
        int target = arr[arr.size()/2];
        int ans = 0;
        for (int val : arr) {
            ans += abs(val - target) / x;
        }
        return ans;
    }
};
