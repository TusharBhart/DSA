// Memoization
class Solution {
    int dfs(int i, int j, string &s, string &t, vector<vector<int>> &dp) {
        if(j == 0) return i;
        if(i == 0) return j;
        if(dp[i][j] != -1) return dp[i][j];
        
        if(s[i - 1] == t[j - 1]) return dp[i][j] = dfs(i - 1, j - 1, s, t, dp);
        return dp[i][j] = 1 + min(dfs(i - 1, j - 1, s, t, dp), min(dfs(i, j - 1, s, t, dp), dfs(i - 1, j, s, t, dp)));
    }
public:
    int minDistance(string s, string t) {
        int n = s.size(), m = t.size();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));

        return dfs(n, m, s, t, dp);
    }
};

// Tabulation
class Solution {
public:
    int minDistance(string s, string t) {
        int n = s.size(), m = t.size();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1));

        for(int i=0; i<=n; i++) dp[i][0] = i;
        for(int j=0; j<=m; j++) dp[0][j] = j;

        for(int i=1; i<=n; i++) {
            for(int j=1; j<=m; j++) {
                if(s[i - 1] == t[j - 1]) dp[i][j] = dp[i - 1][j - 1];
                else dp[i][j] = 1 + min(dp[i - 1][j - 1], min(dp[i][j - 1], dp[i - 1][j]));
            }
        }
        return dp[n][m];
    }
};

// Space Optimization
class Solution {
public:
    int minDistance(string s, string t) {
        int n = s.size(), m = t.size();
        vector<int> dp(m + 1), temp(m + 1);

        for(int j=0; j<=m; j++) dp[j] = j;

        for(int i=1; i<=n; i++) {
            temp[0] = i;
            for(int j=1; j<=m; j++) {
                if(s[i - 1] == t[j - 1]) temp[j] = dp[j - 1];
                else temp[j] = 1 + min(dp[j - 1], min(temp[j - 1], dp[j]));
            }
            dp = temp;
        }
        return dp[m];
    }
};