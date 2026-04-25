class Solution {
public:
    vector<int> applyOperations(vector<int>& nums) {
        vector<int> ans;
        for (int i = 0; i < nums.size()-1; i++){
            if (nums[i] == nums[i+1]){
                nums[i] *= 2;;
                nums[i+1] = 0;
            }
        }
        for (int n : nums){
            if (n != 0){
                ans.push_back(n);
            }
        }
        while(ans.size() < nums.size()){
            ans.push_back(0);
        }
        return ans;
    }
};
