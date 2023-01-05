// MEMOIZATION
class Solution {
    int dfs(int i, int w, int val[], int wt[], vector<vector<int>> &dp) {
        // if(!w) return 0;
        if(!i) {
            if(wt[0] <= w) return val[0];
            return 0;
        }
        if(dp[i][w] != -1) return dp[i][w];
        
        int notPick = dfs(i - 1, w, val, wt, dp);
        int pick = wt[i] <= w ? val[i] + dfs(i - 1, w - wt[i], val, wt, dp) : 0;
        
        return dp[i][w] = max(pick, notPick);
    }
    public:
    //Function to return max value that can be put in knapsack of capacity W.
    int knapSack(int w, int wt[], int val[], int n) { 
        vector<vector<int>> dp(n, vector<int>(w + 1, -1));
        return dfs(n - 1, w, val, wt, dp);
    }
};

// TABULATION
class Solution {
    public:
    //Function to return max value that can be put in knapsack of capacity W.
    int knapSack(int w, int wt[], int val[], int n) { 
        vector<vector<int>> dp(n, vector<int>(w + 1, 0));
        
        for(int i=0; i<=w; i++){
            if(wt[0] <= i) dp[0][i] = val[0];
        }
        for(int i=1; i<n; i++) {
            for(int t=0; t<=w; t++) {
                int notPick = dp[i - 1][t];
                int pick = wt[i] <= t ? val[i] + dp[i - 1][t - wt[i]] : 0;
                dp[i][t] = max(pick, notPick);
            }
        }
        return dp[n - 1][w];
    }
};

// SPACE OPTIMIZATION - O(2N)
class Solution {
    public:
    //Function to return max value that can be put in knapsack of capacity W.
    int knapSack(int w, int wt[], int val[], int n) { 
        vector<int> dp(w + 1), temp(w + 1);
       
        for(int i=0; i<=w; i++){
            if(wt[0] <= i) dp[i] = val[0];
        }
        for(int i=1; i<n; i++) {
            for(int t=0; t<=w; t++) {
                int notPick = dp[t];
                int pick = wt[i] <= t ? val[i] + dp[t - wt[i]] : 0;
                temp[t] = max(pick, notPick);
            }
            dp = temp;
        }
        return dp[w];
    }
};

// SPACE OPTIMIZATION - O(N)
class Solution {
    public:
    //Function to return max value that can be put in knapsack of capacity W.
    int knapSack(int w, int wt[], int val[], int n) { 
        vector<int> dp(w + 1);

        for(int i=wt[0]; i<=w; i++) dp[i] = val[0];
        
        for(int i=1; i<n; i++) {
            for(int t=w; t>=0; t--) {
                int notPick = dp[t];
                int pick = wt[i] <= t ? val[i] + dp[t - wt[i]] : 0;
                dp[t] = max(pick, notPick);
            }
        }
        return dp[w];
    }
};