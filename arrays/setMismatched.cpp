class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        // vector<int> arr;
        // int count = 0;
        // int find = 0;
        // for (int i = 0; i < nums.size(); i++){
        //     int n = nums[i];
        //     if (nums[i] == nums[i+1]){
        //         count ++;
        //     }
        // }
        // sort(nums.begin(), nums.end());
        int duplicate = -1;
        int missing = -1;
        for (int i = 0; i < nums.size(); i++){
            int val = nums[i];
            if (val < 0)
                val = -val;
            int index = val-1;
            if(nums[index] < 0){
                duplicate = val;
            }
            else{
                nums[index] *= -1;
            }
        }
        for (int i = 0; i < nums.size(); i++){
            if (nums[i] > 0){
                missing = i+1;
                break;
            }
        }
        return {duplicate,missing};
    }
};
