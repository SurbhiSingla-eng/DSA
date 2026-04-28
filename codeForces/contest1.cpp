#include <bits/stdc++.h>
using namespace std;

long long solve(vector<int>& a) {
    int n = a.size();
    vector<long long> dp(n + 1, 1e18);
    dp[0] = 0;

    for (int i = 1; i <= n; i++) {
        long long prod = 1;

        for (int j = i; j >= 1; j--) {
            if (j < i && a[j-1] > a[j]) break;

            prod *= a[j-1];
            dp[i] = min(dp[i], dp[j-1] + prod);
        }
    }

    return dp[n];
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<int> a(n);
        for (int i = 0; i < n; i++) cin >> a[i];

        cout << solve(a) << endl;
    }

    return 0;
}
