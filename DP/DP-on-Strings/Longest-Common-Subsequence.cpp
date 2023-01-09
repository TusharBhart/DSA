// Memoization 1
class Solution {
    int dfs(int i, int j, string &s1, string &s2, vector<vector<int>> &dp) {
        if(i < 0 || j < 0) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        
        if(s1[i] == s2[j]) return dp[i][j] = 1 + dfs(i - 1, j - 1, s1, s2, dp);

        return dp[i][j] = max(dfs(i - 1, j, s1, s2, dp), dfs(i, j - 1, s1, s2, dp));
    }
public:
    int longestCommonSubsequence(string s1, string s2) {
        int n = s1.size(), m = s2.size();
        vector<vector<int>> dp(n, vector<int> (m, -1));

        return dfs(n - 1, m - 1, s1, s2, dp);
    }
};

// Memoization 2
class Solution {
    int dfs(int i, int j, string &s1, string &s2, vector<vector<int>> &dp) {
        if(i == 0 || j == 0) return 0;
        if(dp[i][j] != -1) return dp[i][j];

        if(s1[i - 1] == s2[j - 1]) return dp[i][j] = 1 + dfs(i - 1, j - 1, s1, s2, dp);

        return dp[i][j] = max(dfs(i - 1, j, s1, s2, dp), dfs(i, j - 1, s1, s2, dp));
    }
public:
    int longestCommonSubsequence(string s1, string s2) {
        int n = s1.size(), m = s2.size();
        vector<vector<int>> dp(n + 1, vector<int> (m + 1, -1));
        
        return dfs(n, m, s1, s2, dp);
    }
};

// Tabulation
class Solution {
public:
    int longestCommonSubsequence(string s1, string s2) {
        int n = s1.size(), m = s2.size();
        vector<vector<int>> dp(n + 1, vector<int> (m + 1, 0));
        
        for(int i=1; i<=n; i++) {
            for(int j=1; j<=m; j++) {
                if(s1[i - 1] == s2[j - 1]) dp[i][j] = 1 + dp[i - 1][j - 1];
                else  dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
        return dp[n][m];
    }
};

// Space Optimization
class Solution {
public:
    int longestCommonSubsequence(string s1, string s2) {
        int n = s1.size(), m = s2.size();
        vector<int> dp(m + 1), temp(m + 1);
        
        for(int i=1; i<=n; i++) {
            for(int j=1; j<=m; j++) {
                if(s1[i - 1] == s2[j - 1]) temp[j] = 1 + dp[j - 1];
                else  temp[j] = max(dp[j], temp[j - 1]);
            }
            dp = temp;
        }
        return dp[m];
    }
};