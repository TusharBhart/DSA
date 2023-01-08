// Memoization
class Solution{
    int dfs(int i, int t, int price[], vector<vector<int>> &dp) {
        if(!t) return 0;
        if(!i) return price[0] * t;
        if(dp[i][t] != -1) return dp[i][t];
        
        int notPick = 0 + dfs(i - 1, t, price, dp);
        int pick = i + 1 <= t ? price[i] + dfs(i, t - i - 1, price, dp) : 0;
        
        return dp[i][t] = max(pick, notPick);
    }
  public:
    int cutRod(int price[], int n) {
        vector<vector<int>> dp(n, vector<int>(n + 1, -1));
        return dfs(n - 1, n, price, dp);
    }
};

// Tabulation
class Solution{
  public:
    int cutRod(int price[], int n) {
        vector<vector<int>> dp(n, vector<int>(n + 1));
        
        for(int t=0; t<=n; t++) dp[0][t] = price[0] * t;
        
        for(int i=1; i<n; i++) {
            for(int t=1; t<=n; t++) {
                int notPick = 0 + dp[i - 1][t];
                int pick = i + 1 <= t ? price[i] + dp[i][t - i - 1] : 0;
                
                dp[i][t] = max(pick, notPick);
            }
        }
        return dp[n - 1][n];
    }
};

// Space Optimization O(2 * N)
class Solution{
  public:
    int cutRod(int price[], int n) {
        vector<int> dp(n + 1), temp(n + 1);
        
        for(int t=0; t<=n; t++) dp[t] = price[0] * t;
        
        for(int i=1; i<n; i++) {
            for(int t=1; t<=n; t++) {
                int notPick = 0 + dp[t];
                int pick = i + 1 <= t ? price[i] + temp[t - i - 1] : 0;
                
                temp[t] = max(pick, notPick);
            }
            dp = temp;
        }
        return dp[n];
    }
};

// Space Optimization O(N)
class Solution{
  public:
    int cutRod(int price[], int n) {
        vector<int> dp(n + 1);
        
        for(int t=0; t<=n; t++) dp[t] = price[0] * t;
        
        for(int i=1; i<n; i++) {
            for(int t=1; t<=n; t++) {
                int notPick = 0 + dp[t];
                int pick = i + 1 <= t ? price[i] + dp[t - i - 1] : 0;
                
                dp[t] = max(pick, notPick);
            }
        }
        return dp[n];
    }
};