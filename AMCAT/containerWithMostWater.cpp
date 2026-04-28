// class Solution {
// public:
//     int maxArea(vector<int>& height) {
//       // area of rectangle = size * height;
//       int maxi = 0;
//     //   int first = height[0];
//     //   int last = height.size()-1;
//       for (int i = 0; i < height.size(); i++){
//         int area = 0;
//         for (int j = i+1; j < height.size(); j++){
//             if (height[i] > height[j]){
//                 area = height[j] * abs(i-j);
//             }
//             else{
//                 area = height[i] * abs(i-j);
//             }
//             if (area > maxi){
//                 maxi = area;
//             }
//         }
//        }
//        return maxi;
//     }
// };
class Solution{
public:
    int maxArea(vector<int>& height) {
    int left = 0, right = height.size() - 1;
    int maxi = 0;

    while (left < right) {
        int area = min(height[left], height[right]) * (right - left);
        maxi = max(maxi, area);

        if (height[left] < height[right])
            left++;
        else
            right--;
    }
    return maxi;
}
};
