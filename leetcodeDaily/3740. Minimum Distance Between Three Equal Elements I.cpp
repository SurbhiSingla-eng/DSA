class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        int distance = INT_MAX;
        int indistance = distance;
        // int i,j,k;
        for ( int i = 0; i < nums.size(); i++){
            for (int j = i+1; j < nums.size(); j++){
                for (int k = j+1; k < nums.size(); k++){
                    if(nums[i] == nums[j] && nums[j] == nums[k]){
                        int current = abs(i - j) + abs(j - k) + abs(k - i);
                        if (current < distance){
                            distance = current;
                        }
                    }
                    // else{
                    //     distance = -1;
                    //  }
                }
            }
        }
        if (distance == indistance){
            distance = -1;
        }
        return distance;
    }
};
