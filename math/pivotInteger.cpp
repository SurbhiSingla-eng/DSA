class Solution {
public:
    int pivotInteger(int n) {
    //     int sumH = n;
    //     int sumL = 0;
    //     int x = n/2;
    //     for (int i = 2; i <= n; i++){
    //         sumL += i + i;
    //         sumH += (n-1);
    //     }
    //     if (sumL != sumH){
    //         return -1;
    //     }
    //     return x;
    // }
    int totalSum = n * (n + 1) / 2;
    int sum = 0; 
    for (int i = 1; i <= n; i++){
        sum += i;
        if ( sum == (totalSum - sum +i)){
            return i;
        }
    }
    return -1;
    }
};
