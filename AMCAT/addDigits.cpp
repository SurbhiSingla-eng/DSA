class Solution {
public:
    int divide(int n ){
        int sum = 0;
        while (n > 0){
            int rem = n % 10;
            sum += rem;
            n /= 10;
        }
        return sum;
    }
    int addDigits(int num) {
       int sum = divide(num);
        while (sum >= 10){
           sum = divide(sum);
        }
        return sum;
    }
};
