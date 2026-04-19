// class Solution {
// public:
//     int maxDistance(vector<int>& nums1, vector<int>& nums2) {
//         // sort(nums1.begin(), nums1.end());
//         // sort(nums2.begin(), nums2.end());
//         int maxi = 0;
//         for (int i = 0; i < nums1.size(); i++){
//             for (int j = 0; j < nums2.size(); j++){
//                 if(i <= j  && nums1[i] <= nums2[j]){
//                     int dist = j - i;
//                     if ( dist > maxi){
//                         maxi = dist;
//                     }
//                 }
//             }
//         }
//         return maxi;
//     }
// };

class Solution {
public:
    int maxDistance(vector<int>& nums1, vector<int>& nums2) {
        int i = 0, j = 0, maxi = 0;
        while (i < nums1.size() && j < nums2.size()) {
            if (nums1[i] <= nums2[j]) {
                maxi = max(maxi, j - i);
                j++;
            } else {
                i++;
            }
        }
        return maxi;
    }
};
