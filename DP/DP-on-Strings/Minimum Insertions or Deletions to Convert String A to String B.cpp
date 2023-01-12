class Solution{
	int dfs(int i, int j, string &s, string &t, vector<vector<int>> &dp) {
	    if(i < 0 || j < 0) return 0;
	    if(dp[i][j] != -1) return dp[i][j];
	    
	    if(s[i] == t[j]) return dp[i][j] = 1 + dfs(i - 1, j - 1, s, t, dp);
	    return dp[i][j] = max(dfs(i - 1, j, s, t, dp), dfs(i, j - 1, s, t, dp));
	}

	public:
	int minOperations(string s, string t) { 
	    int n = s.size(), m = t.size();
	    vector<vector<int>> dp(n, vector<int>(m, -1));
	    
	    int l = dfs(n - 1, m - 1, s, t, dp);
	    return n - l + m - l;
	    
	} 
};