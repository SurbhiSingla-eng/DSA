class Solution {
public:
    string removeDuplicateLetters(string s) {
        unordered_map<char, int> last;
        unordered_set<char> used;
        for (int i = 0; i < s.size(); i++) {
            last[s[i]] = i;
        }
        string res = "";
        for (int i = 0; i < s.size(); i++) {
            char c = s[i];
            if (used.count(c)) continue;
            while (!res.empty() && 
                   res.back() > c && 
                   last[res.back()] > i) {
                used.erase(res.back());
                res.pop_back();
            }
            res.push_back(c);
            used.insert(c);
        }
        return res;
    }
};
