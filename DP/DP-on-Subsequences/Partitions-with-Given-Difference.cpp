// MEMOIZATION
class Solution {
    int mod = 1e9 + 7;
    int dfs(int i, int t, vector<int> &arr, vector<vector<int>> &dp) {
        if(!i) {
            if(!t && !arr[0]) return 2;
            if(!t) return 1;
            return arr[0] == t;
        }
        if(dp[i][t] != -1) return dp[i][t];
        
        int notPick = dfs(i - 1, t, arr, dp);
        int pick = arr[i] <= t ? dfs(i - 1, t - arr[i], arr, dp) : 0;
        
        return dp[i][t] = (pick + notPick) % mod;
    }
  public:
    int countPartitions(int n, int d, vector<int>& arr) {
        int ts = 0;
        for(int i : arr) ts += i;
        if(d + ts < 2 || (d + ts) % 2) return 0;
        ts = (d + ts) / 2;
        vector<vector<int>> dp(n, vector<int>(ts + 1, -1));
        return dfs(n - 1, ts, arr, dp);
    }
};

// TABULATION
class Solution {
    int mod = 1e9 + 7;
  public:
    int countPartitions(int n, int d, vector<int>& arr) {
        int ts = 0;
        for(int i : arr) ts += i;
        if(d + ts < 2 || (d + ts) % 2) return 0;
        ts = (d + ts) / 2;
        
        vector<vector<int>> dp(n, vector<int>(ts + 1));
        
        dp[0][0] = 1;
        if(arr[0] <= ts) dp[0][arr[0]] = 1;
        if(!arr[0]) dp[0][0] = 2;
        
        for(int i=1; i<n; i++) {
            for(int t=0; t<=ts; t++) {
                int notPick = dp[i - 1][t];
                int pick = arr[i] <= t ? dp[i - 1][t - arr[i]] : 0;
                
                dp[i][t] = (pick + notPick) % mod;
            }
        }
        return dp[n - 1][ts];
    }
};

// SPACE OPTIMIZATION
class Solution {
    int mod = 1e9 + 7;
  public:
    int countPartitions(int n, int d, vector<int>& arr) {
        int ts = 0;
        for(int i : arr) ts += i;
        if(d + ts < 2 || (d + ts) % 2) return 0;
        ts = (d + ts) / 2;
        
        vector<int> dp(ts + 1), temp(ts + 1);
        
        dp[0] = 1;
        if(arr[0] <= ts) dp[arr[0]] = 1;
        if(!arr[0]) dp[0] = 2;
        
        for(int i=1; i<n; i++) {
            for(int t=0; t<=ts; t++) {
                int notPick = dp[t];
                int pick = arr[i] <= t ? dp[t - arr[i]] : 0;
                
                temp[t] = (pick + notPick) % mod;
            }
            dp = temp;
        }
        return dp[ts];
    }
};