// Memoization
class Solution {
    int dfs(int i, int buy, int c, vector<int> &p, vector<vector<vector<int>>> &dp) {
        if(!c || i == p.size()) return 0;
        if(dp[i][buy][c] != -1) return dp[i][buy][c];

        if(buy) {
            return dp[i][buy][c] = max(-p[i] + dfs(i + 1, 0, c, p, dp), 0 + dfs(i + 1, 1, c, p, dp));
        }
        return dp[i][buy][c] = max(p[i] + dfs(i + 1, 1, c - 1, p, dp), 0 + dfs(i + 1, 0, c, p, dp));
    }
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>> (2, vector<int> (3, -1)));

        return dfs(0, 1, 2, prices, dp);
    }
}; 

// Tabulation
class Solution {
public:
    int maxProfit(vector<int>& p) {
        int n = p.size();
        vector<vector<vector<int>>> dp(n + 1, vector<vector<int>> (2, vector<int> (3)));

        for(int i=n-1; i>=0; i--) {
            for(int buy=0; buy<=1; buy++) {
                for(int c=1; c<=2; c++) {
                    if(buy) dp[i][buy][c] = max(-p[i] + dp[i + 1][0][c], 0 + dp[i + 1][1][c]);
                    else dp[i][buy][c] = max(p[i] + dp[i + 1][1][c - 1], 0 + dp[i + 1][0][c]);
                }
            }
        }
        return dp[0][1][2];
    }
}; 

// Space Optimization
class Solution {
public:
    int maxProfit(vector<int>& p) {
        int n = p.size();
        vector<vector<int>> dp(2, vector<int> (3)), temp(2, vector<int> (3));

        for(int i=n-1; i>=0; i--) {
            for(int buy=0; buy<=1; buy++) {
                for(int c=1; c<=2; c++) {
                    if(buy) temp[buy][c] = max(-p[i] + dp[0][c], 0 + dp[1][c]);
                    else temp[buy][c] = max(p[i] + dp[1][c - 1], 0 + dp[0][c]);
                }
            }
            dp = temp;
        }
        return dp[1][2];
    }
}; 