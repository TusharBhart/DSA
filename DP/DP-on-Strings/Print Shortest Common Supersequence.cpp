class Solution {
public:
    string shortestCommonSupersequence(string s, string t) {
        int n = s.size(), m = t.size();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1));

        for(int i=1; i<=n; i++) {
            for(int j=1; j<=m; j++) {
                if(s[i - 1] == t[j - 1]) dp[i][j] = 1 + dp[i - 1][j - 1];
                else dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }

        int i = n, j = m;
        string ans;
        while(i && j) {
            if(s[i - 1] == t[j - 1]) {
                ans += s[i - 1];
                i--, j--;
            }
            else if(dp[i - 1][j] > dp[i][j - 1]) ans += s[i - 1], i--;
            else ans += t[j - 1], j--;
        }
        while(i) ans += s[--i];
        while(j) ans += t[--j];

        reverse(ans.begin(), ans.end());
        return ans;
    }
};