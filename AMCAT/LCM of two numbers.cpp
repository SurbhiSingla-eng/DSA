class Solution {
  public:
    int lcm(int a, int b) {
        // code here
        for (int i = 2; i <= a*b; i++){
            if (i % a == 0 && i % b == 0){
                return i;
            }
        }
        return 0;
    }
};
