class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<int> arr;
        int n = nums.size();
        // int n = nums.size();
        // // bool present = true;
        // sort(nums.begin(), nums.end());
        // for (int i = 1; i < n; i++){
        //     // if (nums[i] != i){
        //     //     arr.push_back(i);
        //     // }
        //     // for (int j = 0; j < n; j++){
        //     //     if ( i != nums[j]){
        //     //         arr.push_back(i);
        //     //     }
        //     }
        // }
        set<int> s(nums.begin(), nums.end());
        // sort(nums.begin(), nums.end());
        int hey = 1;
        for (int i : s){
            while (i > hey){
                arr.push_back(hey);
                hey++;
            }
            hey++;
        }
        while (hey <= n) {
            arr.push_back(hey);
            hey++;
        }
        return arr;
    }
};
