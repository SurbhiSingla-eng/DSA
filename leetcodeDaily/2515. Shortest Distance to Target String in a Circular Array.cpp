class Solution {
public:
    int closestTarget(vector<string>& words, string target, int start) {
        for (int i = 0; i <= words.size()/2; i++)
            if (words[(start + i) % words.size()] == target |
                words[(start - i + words.size()) % words.size()] == target)
                return i;           
        return -1;
    }
};
