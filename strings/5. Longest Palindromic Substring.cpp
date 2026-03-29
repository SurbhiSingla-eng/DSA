class Solution {
public:
    string longestPalindrome(string s) {
        if (s.size() < 2){
            return s;
        }
        int start = 0;
        int maxLen = 1;
        for (int i = 0; i < s.size(); i++){
            int l = i;
            int r = i;
            while (l >= 0 && r < s.size() && s[l] == s[r]){
                if (r - l + 1 > maxLen){
                    start = l;
                    maxLen = r - l +1;
                }
                l--;
                r++;
            }
            l = i;
            r = i+1;
            while (l >= 0 && r < s.size() && s[l] == s[r]){
                if (r - l + 1 > maxLen){
                    start = l;
                    maxLen = r - l +1;
                }
                l--;
                r++;
            }
        }
        string result = "";
        for (int i = start; i < start + maxLen; i++){
            result += s[i];
        }
        return result;
    }
};
