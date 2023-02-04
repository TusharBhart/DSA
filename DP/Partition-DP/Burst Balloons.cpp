// Memoization
class Solution {
    int dfs(int i, int j, vector<int> &nums, vector<vector<int>> &dp) {
        if(i > j) return 0;
        if(dp[i][j] != -1) return dp[i][j];

        int ans = -1;
        for(int k=i; k<=j; k++) {
            ans = max(ans, nums[i - 1] * nums[k] * nums[j + 1] + dfs(i, k - 1, nums, dp) + dfs(k + 1, j, nums, dp));
        }
        return dp[i][j] = ans;
    }
public:
    int maxCoins(vector<int>& nums) {
        nums.insert(nums.begin(), 1);
        nums.push_back(1);
        int n = nums.size();

        vector<vector<int>> dp(n, vector<int>(n, -1));
        return dfs(1, n - 2, nums, dp);
    }
};

// Tabulation
class Solution {
public:
    int maxCoins(vector<int>& nums) {
        nums.insert(nums.begin(), 1);
        nums.push_back(1);
        int n = nums.size();

        vector<vector<int>> dp(n, vector<int>(n));

        for(int i=n-2; i>=1; i--) {
            for(int j=1; j<=n-2; j++) {
                if(i > j) continue;
                int ans = -1;
                for(int k=i; k<=j; k++) {
                    ans = max(ans, nums[i - 1] * nums[k] * nums[j + 1] + dp[i][k - 1] + dp[k + 1][j]);
                }
                dp[i][j] = ans;
            }
        }
        return dp[1][n - 2];
    }
};