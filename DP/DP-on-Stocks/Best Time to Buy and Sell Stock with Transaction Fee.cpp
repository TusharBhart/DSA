// Memoization
class Solution {
    int dfs(int i, int buy, int n, vector<int> &p, vector<vector<int>> &dp, int fee) {
        if(i == n) return 0;
        if(dp[i][buy] != -1) return dp[i][buy];

        if(buy) {
            return dp[i][buy] = max(-p[i] + dfs(i + 1, 0, n, p, dp, fee), dfs(i + 1, 1, n, p, dp, fee));
        }
        return dp[i][buy] = max(p[i] - fee + dfs(i + 1, 1, n, p, dp, fee), dfs(i + 1, 0, n, p, dp, fee));
    }
public:
    int maxProfit(vector<int>& p, int fee) {
        int n = p.size(), cnt = 0;
        vector<vector<int>> dp(n, vector<int>(2, -1));
        return dfs(0, 1, n, p, dp, fee);
    }
};

// Tabulation
class Solution {
public:
    int maxProfit(vector<int>& p, int fee) {
        int n = p.size();
        vector<vector<int>> dp(n + 1, vector<int>(2));
        
        for(int i=n-1; i>=0; i--) {
            for(int buy=0; buy<=1; buy++) {
                if(buy) {
                    dp[i][buy] = max(-p[i] + dp[i + 1][0], dp[i + 1][1]);
                }
                else dp[i][buy] = max(p[i] - fee + dp[i + 1][1], dp[i + 1][0]);
            }
        }
        return dp[0][1];
    }
};

// Space Optimization
class Solution {
public:
    int maxProfit(vector<int>& p, int fee) {
        int n = p.size();
        vector<int> dp(2), temp(2);
        
        for(int i=n-1; i>=0; i--) {
            for(int buy=0; buy<=1; buy++) {
                if(buy) {
                    temp[buy] = max(-p[i] + dp[0], dp[1]);
                }
                else temp[buy] = max(p[i] - fee + dp[1], dp[0]);
            }
            dp = temp;
        }
        return dp[1];
    }
};