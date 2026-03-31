class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int max = 0;
        int target = 1;
        int value = 0;
        for (int i = 0; i < nums.size(); i++){ 
            if (nums[i] == target){
                value++;
                if (value > max){
                    max = value;
                }
            }
            else{
                    value = 0;
            }
        }
        return max;
    }
};
