// Memoization
class Solution {
    int dfs(int i, int buy, int n, vector<int> &prices, vector<vector<int>> &dp) {
        if(i == n) return 0;
        if(dp[i][buy] != -1) return dp[i][buy];

        int profit = 0;
        if(buy) {
            profit = max(-prices[i] + dfs(i + 1, 0, n, prices, dp), 0 + dfs(i + 1, 1, n, prices, dp));
        }
        else {
            profit = max(prices[i] + dfs(i + 1, 1, n, prices, dp), 0 + dfs(i + 1, 0, n, prices, dp));
        }
        return dp[i][buy] = profit;
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
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n + 1, vector<int>(2));

        for(int i=n-1; i>=0; i--) {
            for(int buy=0; buy<=1; buy++) {
                int profit = 0;
                if(buy) {
                    profit = max(-prices[i] + dp[i + 1][0], 0 + dp[i + 1][1]);
                }
                else {
                    profit = max(prices[i] + dp[i + 1][1], 0 + dp[i + 1][0]);
                }
                dp[i][buy] = profit;
            }
        }
        return dp[0][1];
    }
};

// Space Optimization
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<int> dp(2), temp(2);

        for(int i=n-1; i>=0; i--) {
            for(int buy=0; buy<=1; buy++) {
                int profit = 0;
                if(buy) {
                    profit = max(-prices[i] + dp[0], 0 + dp[1]);
                }
                else {
                    profit = max(prices[i] + dp[1], 0 + dp[0]);
                }
                temp[buy] = profit;
            }
            dp = temp;
        }
        return dp[1];
    }
};

// Greedy
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size(), ans = 0;
        for(int i=1; i<n; i++) ans += max(0, prices[i] - prices[i - 1]);
        return ans;
    }
};