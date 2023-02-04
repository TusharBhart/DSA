// Memoization
class Solution {
    int dfs(int i, int j, vector<int> &cuts, vector<vector<int>> &dp) {
        if(i > j) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        int ans = 1e9;
        for(int k=i; k<=j; k++) {
            ans = min(ans, cuts[j + 1] - cuts[i - 1] + dfs(i, k - 1, cuts, dp) + dfs(k + 1, j, cuts, dp));
        }
        return dp[i][j] = ans;
    }
public:
    int minCost(int n, vector<int>& cuts) {
        int m = cuts.size();
        cuts.insert(cuts.begin(), 0);
        cuts.push_back(n);
        sort(cuts.begin(), cuts.end());

        vector<vector<int>> dp(m + 1, vector<int>(m + 1, -1));
        return dfs(1, m, cuts, dp);
    }
};

// Tabulation
class Solution {
public:
    int minCost(int n, vector<int>& cuts) {
        int m = cuts.size();
        cuts.insert(cuts.begin(), 0);
        cuts.push_back(n);
        sort(cuts.begin(), cuts.end());

        vector<vector<int>> dp(m + 2, vector<int>(m + 2));

        for(int i=m; i>=1; i--) {
            for(int j=1; j<=m; j++) {
                if(i > j) continue;
                int ans = 1e9;
                for(int k=i; k<=j; k++) {
                    ans = min(ans, cuts[j + 1] - cuts[i - 1] + dp[i][k - 1] + dp[k + 1][j]);
                }
                dp[i][j] = ans;
            }
        }
        return dp[1][m];
    }
};