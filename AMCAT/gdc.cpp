class Solution {
public:
    int findGCD(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int l = nums[0];
        int h = nums[nums.size()-1];
        int gcd = 1;
        for(int i = 1; i <= l; i++){
            if (l % i == 0 && h % i == 0){
                if (i > gcd){
                    gcd = i;
                }
            }
        }
        return gcd;
    }
};
