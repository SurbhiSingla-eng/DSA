// class Solution {
// public:
//     // int func(int num){
//     //     int dist = 0;
//     //     dist += |i-j|;
//     // }
//     vector<long long> distance(vector<int>& nums) {
//         vector<long long> arr;
//         int j = nums[0];
//         for (int i = 1; i < nums.size(); i++){
//             // vector<int> ar;
//             if(nums[i] != j){
//                 arr.push_back(0);
//             }  
//             else{
//                 int dist = 0;
//                 dist += abs(nums[i]-j);
//                 arr.push_back(dist);
//             }
//             // i++;
//         }
//         j++;
//         return arr;
//     }
// };

// nested loops 
// class Solution{
//     public:
//     vector<long long> distance(vector<int>& nums){
//         vector<long long> arr;
//         for (int i = 0; i < nums.size(); i++){
//             long long dist = 0;
//             for (int j = 0; j < nums.size(); j++){
//                 if (nums[i] == nums[j]){
//                     dist += abs(i - j);
//                 }
//                 // else{
//                 //     dist = 0;
//                 // }
//             }
//             arr.push_back(dist);
//         }
//         return arr;
//     }
// };

//O(n logn)
class Solution {
public:
    vector<long long> distance(vector<int>& nums) {
        int n = nums.size();
        vector<pair<int,int>> v;
        for (int i = 0; i < n; i++) {
            v.push_back({nums[i], i});
        }
        sort(v.begin(), v.end());   
        vector<long long> res(n);
        int i = 0;
        while (i < n) {
            int j = i;
            while (j < n && v[j].first == v[i].first) j++;
            vector<int> idx;
            for (int k = i; k < j; k++) {
                idx.push_back(v[k].second);
            }
            sort(idx.begin(), idx.end());
            int m = idx.size();
            vector<long long> prefix(m);
            prefix[0] = idx[0];
            for (int k = 1; k < m; k++) {
                prefix[k] = prefix[k-1] + idx[k];
            }
            for (int k = 0; k < m; k++) {
                long long left = (long long)idx[k]*k - (k ? prefix[k-1] : 0);
                long long right = (prefix[m-1] - prefix[k]) - (long long)idx[k]*(m-k-1);
                res[idx[k]] = left + right;
            }
            i = j;
        }
        return res;
    }
};
