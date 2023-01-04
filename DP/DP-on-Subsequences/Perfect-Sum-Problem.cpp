class Solution{
    int mod = 1e9 + 7;
    int dfs(int i, int t, int arr[], vector<vector<int>> &dp) {
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
	int perfectSum(int arr[], int n, int sum) {
        vector<vector<int>> dp(n, vector<int>(sum + 1, -1));
        return dfs(n - 1, sum, arr, dp);
	}
	  
};