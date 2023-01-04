// MEMOIZATION
class Solution{
    int dfs(int i, long long cs, long long ts, int arr[], vector<vector<int>> & dp) {
        if(i < 0|| cs == ts) return abs(cs - (ts - cs));
        if(dp[i][cs] != -1) return dp[i][cs];
        
        int notTake = dfs(i - 1, cs, ts, arr, dp);
        int take = dfs(i - 1, cs + arr[i], ts, arr, dp);
        
        return dp[i][cs] = min(take, notTake);
    }

  public:
	int minDifference(int arr[], int n)  { 
	    long long ts = 0, cs = 0;
	    for(int i=0; i<n; i++) ts += arr[i];
	    
	    vector<vector<int>> dp(n, vector<int>(ts + 1, -1));
	    return dfs(n - 1, cs, ts, arr, dp);
	} 
};

// TABULATION
class Solution{

  public:
	int minDifference(int arr[], int n)  { 
	    long long ts = 0;
	    for(int i=0; i<n; i++) ts += arr[i];
	    long long target = ts / 2;
	    
	    vector<vector<bool>> dp(n, vector<bool>(target + 1));
	    if(arr[0] <= target) dp[0][arr[0]] = true;
	    for(int i=0; i<n; i++) dp[i][0] = true;
	    
	    for(int i=1; i<n; i++) {
	        for(int t=1; t<=target; t++) {
	            int notTake = dp[i - 1][t];
	            int take = arr[i] <= t ? dp[i - 1][t - arr[i]] : false;
	            dp[i][t] = take || notTake;
	        }
	    }
	    
	    int ans = INT_MAX;
	    for(int i=0; i<=target; i++) {
	        if(dp[n - 1][i]) ans = min(ans, (int) abs((ts - i) - i));
	    }
	    return ans;
	} 
};