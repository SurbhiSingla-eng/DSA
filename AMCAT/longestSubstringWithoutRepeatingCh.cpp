class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        string a = "";
        int size = 0;
        for (int i = 0; i < s.size(); i++){
            while(a.find(s[i]) != -1){
                a.erase(0,1);
            }
            a.push_back(s[i]);
            if (size < a.size()){
                size = a.size();
            }
        }
        return size;
    }
};
