// Memoization
class Solution {
    int dfs(int i, int j, string &s, string &t, vector<vector<int>> &dp) {
        if(j == 0) return 1;
        if(i == 0) return 0;
        if(dp[i][j] != -1) return dp[i][j];

        if(s[i - 1] == t[j - 1]) return dp[i][j] = dfs(i - 1, j - 1, s, t, dp) + dfs(i - 1, j, s, t, dp);
        return dp[i][j] = dfs(i - 1, j, s, t, dp);
    }
public:
    int numDistinct(string s, string t) {
        int n = s.size(), m = t.size();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));

        return dfs(n, m, s, t, dp);
    }
};

// Tabulation
class Solution {
public:
    int numDistinct(string s, string t) {
        int n = s.size(), m = t.size();
        vector<vector<unsigned int>> dp(n + 1, vector<unsigned int>(m + 1));

        for(int i=0; i<=n; i++) dp[i][0] = 1;

        for(int i=1; i<=n; i++) {
            for(int j=1; j<=m; j++) {
                if(s[i - 1] == t[j - 1]) dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
                else dp[i][j] = dp[i - 1][j];
            }
        }
        return dp[n][m];
    }
};

// Space Optimation (2 Arrays)
class Solution {
public:
    int numDistinct(string s, string t) {
        int n = s.size(), m = t.size();
        vector<unsigned int> dp(m + 1), temp(m + 1);

        dp[0] = temp[0] = 1;

        for(int i=1; i<=n; i++) {
            for(int j=1; j<=m; j++) {
                if(s[i - 1] == t[j - 1]) temp[j] = dp[j - 1] + dp[j];
                else temp[j] = dp[j];
            }
            dp = temp;
        }
        return dp[m];
    }
};

// Space Optimation (1 Array)
class Solution {
public:
    int numDistinct(string s, string t) {
        int n = s.size(), m = t.size();
        vector<unsigned int> dp(m + 1);

        dp[0] = 1;

        for(int i=1; i<=n; i++) {
            for(int j=m; j>=1; j--) {
                if(s[i - 1] == t[j - 1]) dp[j] = dp[j - 1] + dp[j];
            }
        }
        return dp[m];
    }
};