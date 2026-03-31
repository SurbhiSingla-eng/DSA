class Solution {
  public:
    vector<int> findUnion(vector<int> &a, vector<int> &b) {
        // code here
        vector<int> arr;
        for (int i = 0; i < a.size(); i++){
            arr.push_back(a[i]);
        }
        for (int j = 0; j < b.size(); j++){
            arr.push_back(b[j]);
        }
    sort(arr.begin(), arr.end());
    arr.erase(unique(arr.begin(), arr.end()), arr.end());
        return arr;
    }
};
