// Memoization
class Solution{
    int dfs(int i, int t, int val[], int wt[], vector<vector<int>> &dp) {
        if(!i) {
            if(t >= wt[0]) return (t / wt[0]) * val[0];
            return 0;
        }
        if(dp[i][t] != -1) return dp[i][t];
        
        int notPick = 0 + dfs(i - 1, t, val, wt, dp);
        int pick = wt[i] <= t ? val[i] + dfs(i, t - wt[i], val, wt, dp) : 0;
        
        return dp[i][t] = max(pick, notPick);
    }
public:
    int knapSack(int n, int w, int val[], int wt[]) {
        vector<vector<int>> dp(n, vector<int>(w + 1, -1));
        return dfs(n - 1, w, val, wt, dp);
    }
};

// Tabulation
class Solution{
public:
    int knapSack(int n, int w, int val[], int wt[]) {
        vector<vector<int>> dp(n, vector<int>(w + 1));
        
        for(int t=wt[0]; t<=w; t++) dp[0][t] = (t / wt[0]) * val[0];
        
        for(int i=1; i<n; i++) {
            for(int t=0; t<=w; t++) {
                int notPick = 0 + dp[i - 1][t];
                int pick = wt[i] <= t ? val[i] + dp[i][t - wt[i]] : 0;
                
                dp[i][t] = max(pick, notPick);
            }
        }
        return dp[n - 1][w];
    }
};

// Space Optimization O(2 * N)
class Solution{
public:
    int knapSack(int n, int w, int val[], int wt[]) {
        vector<int> dp(w + 1), temp(w + 1);
        
        for(int t=wt[0]; t<=w; t++) dp[t] = (t / wt[0]) * val[0];
        
        for(int i=1; i<n; i++) {
            for(int t=0; t<=w; t++) {
                int notPick = 0 + dp[t];
                int pick = wt[i] <= t ? val[i] + temp[t - wt[i]] : 0;
                
                temp[t] = max(pick, notPick);
            }
            dp = temp;
        }
        return dp[w];
    }
};

// Space Optimization O(N)
class Solution{
public:
    int knapSack(int n, int w, int val[], int wt[]) {
        vector<int> dp(w + 1);
        
        for(int t=wt[0]; t<=w; t++) dp[t] = (t / wt[0]) * val[0];
        
        for(int i=1; i<n; i++) {
            for(int t=0; t<=w; t++) {
                int notPick = 0 + dp[t];
                int pick = wt[i] <= t ? val[i] + dp[t - wt[i]] : 0;
                
                dp[t] = max(pick, notPick);
            }
        }
        return dp[w];
    }
};
