// class Solution {
// public:
//     int pivotIndex(vector<int>& nums) {
//         int n = nums.size();
//         for (int i = 0; i < n; i++) {
//             int leftSum = 0;
//             int rightSum = 0;
//             for (int j = 0; j < i; j++) {
//                 leftSum += nums[j];
//             }
//             for (int j = i + 1; j < n; j++) {
//                 rightSum += nums[j];
//             }
//             if (leftSum == rightSum) {
//                 return i;
//             }
//         }
//         return -1;
//     }
// };


class Solution{
public:
    int pivotIndex(vector<int>& nums){
        int totalSum = 0;
        int leftSum = 0;
        for (int num : nums){
            totalSum += num;
        }
        for (int i = 0; i < nums.size(); i++){
            int rightSum = totalSum - leftSum - nums[i];
            if ( leftSum == rightSum){
                return i;
            }
            leftSum += nums[i];
        }
        return -1;
    }
};
