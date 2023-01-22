// Memoization
class Solution {
    int dfs(int i, int t, int k, int n, vector<int> & p, vector<vector<int>> &dp) {
        if(i == n || t == 2 * k) return 0;
        if(dp[i][t] != -1) return dp[i][t];

        if(t % 2 == 0) {
            return dp[i][t] = max(-p[i] + dfs(i + 1, t + 1, k, n, p, dp), 0 + dfs(i + 1, t, k, n, p, dp));
        }
        return dp[i][t] = max(p[i] + dfs(i + 1, t + 1, k, n, p, dp), 0 + dfs(i + 1, t, k, n, p, dp));
    }
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n, vector<int>(2 * k, -1));
        
        return dfs(0, 0, k, n, prices, dp);
    }
};

// Tabulation
class Solution {
public:
    int maxProfit(int k, vector<int>& p) {
        int n = p.size();
        vector<vector<int>> dp(n + 1, vector<int>(2 * k + 1));
        
        for(int i=n-1; i>=0; i--) {
            for(int t=0; t<2 * k; t++) {
                if(t % 2 == 0) {
                    dp[i][t] = max(-p[i] + dp[i + 1][t + 1], 0 + dp[i + 1][t]);
                }
                else dp[i][t] = max(p[i] + dp[i + 1][t + 1], 0 + dp[i + 1][t]);
            }
        }
        return dp[0][0];
    }
};

// Space Optimization
class Solution {
public:
    int maxProfit(int k, vector<int>& p) {
        int n = p.size();
        vector<int> dp(2 * k + 1), temp(2 * k + 1);
        
        for(int i=n-1; i>=0; i--) {
            for(int t=0; t<2 * k; t++) {
                if(t % 2 == 0) {
                    temp[t] = max(-p[i] + dp[t + 1], 0 + dp[t]);
                }
                else temp[t] = max(p[i] + dp[t + 1], 0 + dp[t]);
            }
            dp = temp;
        }
        return dp[0];
    }
};