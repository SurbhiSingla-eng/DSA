//O(n)
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int k = 0;
        int n = nums.size();
        for (int i = 0; i <n; i++){
            if (nums[i] != 0){
                int temp = nums[k];
                nums[k] = nums[i];
                nums[i] = temp;
                k++;
            }
        }
    }
};
