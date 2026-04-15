class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> arr;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); i++) {
            for (int j = i + 1; j < nums.size(); j++) {
                for (int k = j + 1; k < nums.size(); k++) {
                    int sum = nums[i] + nums[j] + nums[k];
                    if (sum == 0) {
                        vector<int> triplet = {nums[i], nums[j], nums[k]};
                        bool exists = false;
                        for (int x = 0; x < arr.size(); x++) {
                            if (arr[x][0] == triplet[0] &&
                                arr[x][1] == triplet[1] &&
                                arr[x][2] == triplet[2]) {
                                exists = true;
                                break;
                            }
                        }
                        if (!exists) {
                            arr.push_back(triplet);
                        }
                    }
                }
            }
        }
        return arr;
    }
};
