// Memoization
class Solution {
    int dfs(int i, int t, vector<int> &coins, vector<vector<int>> &dp) {
        if(!t) return 1;
        if(!i) return t % coins[i] == 0;
        if(dp[i][t] != -1) return dp[i][t];
        
        int notPick = dfs(i - 1, t, coins, dp);
        int pick = coins[i] <= t ? dfs(i, t - coins[i], coins, dp) : 0;

        return dp[i][t] = pick + notPick;
    }
public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int>(amount + 1, -1));

        return dfs(n - 1, amount, coins, dp);
    }
};

// Tabulation
class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int>(amount + 1));

        for(int i=0; i<n; i++) dp[i][0] = 1;
        for(int t=0; t<=amount; t++) {
            if(t % coins[0] == 0) dp[0][t] = 1;
        }

        for(int i=1; i<n; i++) {
            for(int t=1; t<=amount; t++ ) {
                int notPick = dp[i - 1][t];
                int pick = coins[i] <= t ? dp[i][t - coins[i]] : 0;

                dp[i][t] = pick + notPick;
            }
        }
        return dp[n - 1][amount];
    }
};

// Space Optimization
class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<int> dp(amount + 1), temp(amount + 1);

        dp[0] = temp[0] = 1;
        for(int t=0; t<=amount; t++) {
            if(t % coins[0] == 0) dp[t] = 1;
        }

        for(int i=1; i<n; i++) {
            for(int t=1; t<=amount; t++) {
                int notPick = dp[t];
                int pick = coins[i] <= t ? temp[t - coins[i]] : 0;

                temp[t] = pick + notPick;
            }
            dp = temp;
        }
        return dp[amount];
    }
};