// MEMOIZATION
class Solution{ 
    bool dfs(int i, int t, vector<int> &arr, vector<vector<int>> &dp) {
        if(!t) return true;
        if(!i) return arr[0] == t;
        if(dp[i][t] != -1) return dp[i][t];
        
        bool nottake = dfs(i - 1, t, arr, dp);
        bool take = arr[i] <= t ? dfs(i - 1, t - arr[i], arr, dp) : false;
        
        return dp[i][t] = take || nottake;
    }
public:
    bool isSubsetSum(vector<int>arr, int sum) {
        int n = arr.size();
        vector<vector<int>> dp(n, vector<int>(sum + 1, -1));
        
        return dfs(n - 1, sum, arr, dp);
    }
};

// TABULATION
class Solution{ 
public:
    bool isSubsetSum(vector<int>arr, int sum) {
        int n = arr.size();
        vector<vector<bool>> dp(n, vector<bool>(sum + 1, false));
        
        for(int i=0; i<n; i++) dp[i][0] = true;
        dp[0][arr[0]] = true;
        
        for(int i=1; i<n; i++) {
            for(int t=1; t<=sum; t++) {
                bool nottake = dp[i - 1][t];
                bool take = arr[i] <= t ? dp[i - 1][t - arr[i]] : false;
                dp[i][t] = take || nottake;
            }
        }
        
        return dp[n - 1][sum];
    }
};

// SPACE OPTIMIZATION
class Solution{ 
public:
    bool isSubsetSum(vector<int>arr, int sum) {
        int n = arr.size();
        vector<bool> dp(sum + 1), temp(sum + 1);
        
        dp[0] = true;
        dp[arr[0]] = true;
        
        for(int i=1; i<n; i++) {
            // vector<bool> temp(sum + 1);
            for(int t=1; t<=sum; t++) {
                bool nottake = dp[t];
                bool take = arr[i] <= t ? dp[t - arr[i]] : false;
                temp[t] = take || nottake;
            }
            dp = temp;
        }
        
        return dp[sum];
    }
};
