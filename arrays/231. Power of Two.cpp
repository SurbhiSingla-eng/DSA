class Solution {
public:
    bool isPowerOfTwo(int n) {
        return n > 0 && (n & (long)n - 1) == 0;
    }
};
//O(1)
