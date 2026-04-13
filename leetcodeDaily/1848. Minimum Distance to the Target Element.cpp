class Solution {
public:
    int getMinDistance(vector<int>& nums, int target, int start) {
        int diff = INT_MAX;
        for (int i = 0; i < nums.size(); i++){
            if (nums[i] == target){
              int min_diff = abs(i - start);
              if (min_diff < diff){
                diff = min_diff;
              }
            }
        }
        return diff;
    }
};
