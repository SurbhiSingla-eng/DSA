class Solution {
public:
    int reverse(int n){
        int newNum = 0;
        while (n != 0){
        int rem = n % 10;
        newNum = newNum * 10 + rem;
        n /= 10;
        }
        return newNum;
        }
    int mirrorDistance(int n) {
        int dist = abs(n - reverse(n));
        return dist;
    }
};
