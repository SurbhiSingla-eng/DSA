class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        // set<int> s(nums.begin(), nums.end());
        // int length = 0;
        // int start = *s.begin();
        // for (int num : s){

        // }
        sort(nums.begin(), nums.end());
        int longest = 1;
        int count = 1;
        if(nums.size() == 0){
            return 0;
        }
        for (int i = 1; i < nums.size(); i++){
            if (nums[i] == nums[i-1]){
                continue;
            }
            if (nums[i] == nums[i-1]+1){
                count++;
            }
            else{
                count = 1;
            }
            if (count > longest){
                longest = count;
            }
        }
        return longest;
    }
};
