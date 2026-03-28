class Solution {
public:
    string findTheString(vector<vector<int>>& lcp) {
        int n = lcp.size();
        string s(n, ' ');
        char cur = 'a';
        for (int i = 0; i < n; ++i) {
            if (s[i] != ' ') 
            continue; 
            if (cur > 'z') 
            return "";  
            for (int j = i; j < n; ++j) {
                if (lcp[i][j] > 0) {
                    s[j] = cur;
                }
            }
            cur++;
        }
        for (int i = n - 1; i >= 0; --i) {
            for (int j = n - 1; j >= 0; --j) {
                int actualLCP = 0;
                if (s[i] == s[j]) {
                    actualLCP = (i + 1 < n && j + 1 < n) ? lcp[i + 1][j + 1] + 1 : 1;
                }
                
                if (lcp[i][j] != actualLCP) {
                    return "";
                }
            }
        }
        return s;
    }
};
