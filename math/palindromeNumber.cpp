class Solution {
public:
    bool isPalindrome(int x) {
        // Negative numbers and numbers ending with 0 (but not 0 itself) cannot be palindromes
        if (x < 0 || (x % 10 == 0 && x != 0)) 
            return false;
        
        int reversed = 0;
        while (x > reversed) {
            int digit = x % 10;
            reversed = reversed * 10 + digit;
            x /= 10;
        }
        
        // For even length, x == reversed
        // For odd length, remove middle digit using reversed/10
        return (x == reversed || x == reversed / 10);
    }
};
