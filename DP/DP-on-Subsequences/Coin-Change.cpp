// Memoization
class Solution {
    int dfs(int i, int t, vector<int> &coins, vector<vector<int>> &dp) {
        if(!i) {
            if(t % coins[0] == 0) return t / coins[0];
            return 1e9;
        }
        if(dp[i][t] != -1) return dp[i][t];

        int notPick = 0 + dfs(i - 1, t, coins, dp);
        int pick = coins[i] <= t ? 1 + dfs(i, t - coins[i], coins, dp) : 1e9;

        return dp[i][t] = min(pick, notPick);
    }
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int>(amount + 1, -1));

        int ans = dfs(n - 1, amount, coins, dp);
        return ans == 1e9 ? -1 : ans;
    }
};

// Tabulation
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int>(amount + 1, 0));
        
        for(int t=0; t<=amount; t++) {
            dp[0][t] = t % coins[0] == 0 ? t / coins[0] : 1e9;
        }

        for(int i=1; i<n; i++) {
            for(int t=0; t<=amount; t++) {
                int notPick = 0 + dp[i - 1][t];
                int pick = coins[i] <= t ? 1 + dp[i][t - coins[i]] : 1e9;

                dp[i][t] = min(pick, notPick);
            }
        }
        return dp[n - 1][amount] == 1e9 ? -1 : dp[n - 1][amount];
    }
};

// Space Optimization
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<int> dp(amount + 1), temp(amount + 1);

        for(int t=0; t<=amount; t++) {
            dp[t] = t % coins[0] == 0 ? t / coins[0] : 1e9;
        }

        for(int i=1; i<n; i++) {
            for(int t=0; t<=amount; t++) {
                int notPick = 0 + dp[t];
                int pick = coins[i] <= t ? 1 + temp[t - coins[i]] : 1e9;

                temp[t] = min(pick, notPick);
            }
            dp = temp;
        }
        return dp[amount] == 1e9 ? -1 : dp[amount];
    }
};