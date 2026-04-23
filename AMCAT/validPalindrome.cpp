class Solution {
public:
    bool isPalindrome(string s) {
        vector<string> orig;
        for (char ch : s){
            if ((ch > 64 && ch < 91) || (ch > 96 && ch < 123) || (ch >= 48 && ch <=57)){
                orig.push_back(string(1,tolower(ch)));
            }
        }
        vector<string> rev = orig;
        reverse(rev.begin(), rev.end());
        if (orig != rev){
            return false;
        }
        return true;
    }
};
