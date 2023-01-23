// Memoization
class Solution {
    int dfs(int i, int buy, int n, vector<int> &p, vector<vector<int>> &dp) {
        if(i >= n) return 0;
        if(dp[i][buy] != -1) return dp[i][buy];

        if(buy) {
            return dp[i][buy] = max(-p[i] + dfs(i + 1, 0, n, p, dp), 0 + dfs(i + 1, 1, n, p, dp));
        }
        return dp[i][buy] = max(p[i] + dfs(i + 2, 1, n, p, dp), 0 + dfs(i + 1, 0, n, p, dp));
    }
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n, vector<int>(2, -1));
        return dfs(0, 1, n, prices, dp);
    }
};

// Tabulation
class Solution {
public:
    int maxProfit(vector<int>& p) {
        int n = p.size();
        vector<vector<int>> dp(n + 2, vector<int>(2));
        
        for(int i=n-1; i>=0; i--) {
            for(int buy=0; buy<=1; buy++) {
                if(buy) {
                    dp[i][buy] = max(-p[i] + dp[i + 1][0], 0 + dp[i + 1][1]);
                }
                else dp[i][buy] = max(p[i] + dp[i + 2][1], 0 + dp[i + 1][0]);
            }
        }
        return dp[0][1];
    }
};

// Space Optimization
class Solution {
public:
    int maxProfit(vector<int>& p) {
        int n = p.size();
        vector<int> dp(2), temp1(2), temp2(2);
        
        for(int i=n-1; i>=0; i--) {
            for(int buy=0; buy<=1; buy++) {
                if(buy) {
                    temp1[buy] = max(-p[i] + dp[0], 0 + dp[1]);
                }
                else temp1[buy] = max(p[i] + temp2[1], 0 + dp[0]);
            }
            temp2 = dp;
            dp = temp1;
        }
        return dp[1];
    }
};