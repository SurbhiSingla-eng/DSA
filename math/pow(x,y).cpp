// class Solution {
// public:
//     double myPow(double x, int n) {
//         double y = x;
//         if (n > 0){
//             for (int i = 1; i < n; i++){
//                 x *= y;
//             }
//         }
//         else if (n < 0){
//             n = -n;
//             for (int i = 1; i < n; i++){
//                 x *= y;
//             }
//             x = 1/x;
//         }
//         else{
//             return 1;
//         }
//         return x;
//     }
// };

class Solution {
public:
    double myPow(double x, int n) {
        long long N = n;          
        double y = x;
        double result = 1;
        if (N < 0){
            y = 1 / y;           
            N = -N;
        }
        while (N > 0){
            if (N % 2 == 1){
                result *= y;
            }
            y *= y;
            N /= 2;
        }
        return result;
    }
};
