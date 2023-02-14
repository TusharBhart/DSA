// Memoization
class Solution {
    int dfs(int i, vector<int> &arr, int k, int n, vector<int> &dp) {
        if(i == n) return 0;
        if(dp[i] != -1) return dp[i];

        int ans = 0, mx = 0;
        for(int j=i; j<min(i+k, n); j++) {
            mx = max(mx, arr[j]);
            ans = max(ans, (j - i + 1) * mx + dfs(j + 1, arr, k, n, dp));
        }
        return dp[i] = ans;
    }
public:
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n = arr.size();
        vector<int> dp(n, -1);
        return dfs(0, arr, k, n, dp);
    }
};

// Tabulation
class Solution {
public:
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n = arr.size();
        vector<int> dp(n + 1);

        for(int i=n-1; i>=0; i--) {
            int ans = 0, mx = 0;
            for(int j=i; j<min(i+k, n); j++) {
                mx = max(mx, arr[j]);
                ans = max(ans, (j - i + 1) * mx + dp[j + 1]);
            }
            dp[i] = ans;
        }
        return dp[0];
    }
};