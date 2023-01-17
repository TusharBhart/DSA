// Memoization
class Solution {
    bool dfs(int i, int j, string &s, string &p, vector<vector<int>> &dp) {
        if(!j) return !i;
        if(!i) {
            for(int k=0; k<j; k++) {
                if(p[k] != '*') return 0;
            }
            return 1;
        }
        if(dp[i][j] != -1) return dp[i][j];

        if(s[i - 1] == p[j - 1] || p[j - 1] == '?') return dp[i][j] = dfs(i - 1, j - 1, s, p, dp);
        if(p[j - 1] == '*') {
            return dp[i][j] = dfs(i, j - 1, s, p, dp) || dfs(i - 1, j, s, p, dp);
        }
        return dp[i][j] = 0;
    }
public:
    bool isMatch(string s, string p) {
        int n = s.size(), m = p.size();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));

        return dfs(n, m, s, p, dp);
    }
};

// Tabulation
class Solution {
public:
    bool isMatch(string s, string p) {
        int n = s.size(), m = p.size();
        vector<vector<bool>> dp(n + 1, vector<bool>(m + 1));

        dp[0][0] = true;
        for(int k=1; k<=m; k++) {
            if(p[k - 1] == '*') dp[0][k] = true;
            else break;
        }

        for(int i=1; i<=n; i++) {
            for(int j=1; j<=m; j++) {
                if(s[i - 1] == p[j - 1] || p[j - 1] == '?') dp[i][j] = dp[i - 1][j - 1];
                if(p[j - 1] == '*') {
                    dp[i][j] = dp[i][j - 1] || dp[i - 1][j];
                }
            }
        }
        return dp[n][m];
    }
};
