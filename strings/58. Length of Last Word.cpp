class Solution {
public:
    int lengthOfLastWord(string s) {
        // char i = s[s.size()-1];
        int count = 0;
        int j = s.size()-1;
        while (j >= 0 && s[j] == ' '){
            j--;
        }
        while (j >= 0 && s[j] != ' '){
            count ++;
            j--;
        }
        return count;
    }
};
