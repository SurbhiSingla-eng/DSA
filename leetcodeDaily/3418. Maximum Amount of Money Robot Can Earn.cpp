// class Solution {
// public:
//     int maximumAmount(vector<vector<int>>& coins) {
//         int max_profit = coins[0][0];
//         int current_profit = coins[0][0];
//         // int position = coins[0][0];
//         for (int i = 0; i < coins.size(); i++){
//             for (int j = 0; j < coins[0].size(); j++){
//                 if (coins[i][j] >= 0){
//                     // position += j;
//                     current_profit += coins[i][j];
//                     if (max_profit < current_profit){
//                         max_profit = current_profit;
//                     }
//                 }
//                 else{
//                     // position += i;
//                     if (max_profit < current_profit){
//                         max_profit = current_profit;
//                     }
//                 }
//             }
//         }
//         return max_profit;
//     }
// };


// class Solution {
// public:
//     int maximumAmount(vector<vector<int>>& coins) {
//         int rows = coins.size();
//         int cols = coins[0].size();
//         int current_profit = 0; 
//         int max_profit = -1e9; 
//         for (int i = 0; i < rows; i++){
//             for (int j = 0; j < cols; j++){
//                 if (coins[i][j] >= 0){
//                     current_profit += coins[i][j];
//                 }
//                 else {
//                     current_profit += coins[i][j];
//                 }
//                 if (current_profit > max_profit) {
//                     max_profit = current_profit;
//                 }
//             }
//         }
//         return current_profit;
//     }
// };


class Solution {
public:
    int maximumAmount(vector<vector<int>>& coins) {
        int rows = coins.size();
        int cols = coins[0].size();
        vector<vector<vector<int>>> dp(rows, vector<vector<int>>(cols, vector<int>(3, -1e9)));
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                for (int k = 0; k < 3; k++) {
                    if (i == 0 && j == 0) {
                        dp[i][j][0] = coins[i][j]; 
                        if (k > 0) dp[i][j][k] = max(dp[i][j][k], 0); 
                        continue;
                    }
                    int prev_max = -1e9;
                    if (i > 0) prev_max = max(prev_max, dp[i-1][j][k]);
                    if (j > 0) prev_max = max(prev_max, dp[i][j-1][k]);
                    dp[i][j][k] = max(dp[i][j][k], prev_max + coins[i][j]);
                    if (k > 0 && coins[i][j] < 0) {
                        int prev_max_with_fewer_skips = -1e9;
                        if (i > 0) prev_max_with_fewer_skips = max(prev_max_with_fewer_skips, dp[i-1][j][k-1]);
                        if (j > 0) prev_max_with_fewer_skips = max(prev_max_with_fewer_skips, dp[i][j-1][k-1]);
                        dp[i][j][k] = max(dp[i][j][k], prev_max_with_fewer_skips);
                    }
                }
            }
        }
        return max({dp[rows-1][cols-1][0], dp[rows-1][cols-1][1], dp[rows-1][cols-1][2]});
    }
};
