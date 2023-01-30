// Memoization
class Solution{
    int dfs(int i, int j, int arr[], vector<vector<int>> &dp) {
        if(i == j) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        
        int ans = 1e9;
        for(int k=i; k<j; k++) {
            int steps = arr[i - 1] * arr[k] * arr[j] + dfs(i, k, arr, dp) + dfs(k + 1, j, arr, dp);
            ans = min(ans, steps);
        }
        return dp[i][j] = ans;
    }
public:
    int matrixMultiplication(int n, int arr[]) {
        vector<vector<int>> dp(n, vector<int> (n, -1));
        return dfs(1, n - 1, arr, dp);
    }
};

// Tabulation
class Solution{
public:
    int matrixMultiplication(int n, int arr[]) {
        vector<vector<int>> dp(n, vector<int>(n));
        
        for(int i=0; i<n; i++) dp[i][i] = 0;
        
        for(int i=n-1; i>0; i--) {
            for(int j=i+1; j<n; j++) {
                int ans = 1e9;
                for(int k=i; k<j; k++) {
                    int s = arr[i - 1] * arr[k] * arr[j] + dp[i][k] + dp[k + 1][j];
                    ans = min(ans, s);
                }
                dp[i][j] = ans;
            }
        }
        return dp[1][n - 1];
    }
};