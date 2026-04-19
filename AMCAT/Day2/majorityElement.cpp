class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int maj = nums.size()/2;
        map<int, int> mpp;
        for (int i = 0; i < nums.size(); i++){
            mpp[nums[i]]++;
            if(mpp[nums[i]] > maj){
                return nums[i];
            }
        }
        return 0;
    }
};
