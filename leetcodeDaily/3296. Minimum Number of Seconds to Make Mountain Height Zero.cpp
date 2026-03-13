class Solution {
public:
    long long minNumberOfSeconds(int mountainHeight, vector<int>& workerTimes) {
        long long low = 0;
        // Upper bound: If one worker with time 10^6 takes all 10^5 height:
        // Time = 10^6 * (10^5 * 10^5+1) / 2 ≈ 5 * 10^15. 
        // 1e16 is a safe upper bound.
        long long high = 1e16; 
        long long ans = high;

        while (low <= high) {
            long long mid = low + (high - low) / 2;
            
            if (canFinish(mid, mountainHeight, workerTimes)) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return ans;
    }

private:
    bool canFinish(long long maxTime, int targetHeight, const vector<int>& workerTimes) {
        long long totalHeightReduced = 0;
        for (int wTime : workerTimes) {
            // Solve for x: wTime * x * (x + 1) / 2 <= maxTime
            // x^2 + x - (2 * maxTime / wTime) <= 0
            // Using quadratic formula: x = (-1 + sqrt(1 + 8 * maxTime / wTime)) / 2
            
            double val = (8.0 * maxTime) / wTime;
            long long x = (sqrt(1.0 + val) - 1.0) / 2.0;
            
            totalHeightReduced += x;
            if (totalHeightReduced >= targetHeight) return true;
        }
        return totalHeightReduced >= targetHeight;
    }
};
