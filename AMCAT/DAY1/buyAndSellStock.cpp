// class Solution {
// public:
//     int maxProfit(vector<int>& prices) {
//         int max = 0;
//         for (int i = 0; i < prices.size(); i++){
//             for ( int j = i+1; j < prices.size(); j++){
//                 int diff = prices[j] - prices[i];
//                 if (diff > max){
//                     max = diff;
//                     //return max;
//                 }
//             }
//         }
//         return max;
//     }
// };
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int mini = prices[0];
        int profit = 0;
        for (int i = 1; i < prices.size(); i++){
            int diff = prices[i] - mini;
            if (diff > profit){
                profit = diff;
            }
            if (prices[i] < mini){
                mini = prices[i];
            }
        }
        return profit;
    }
};
