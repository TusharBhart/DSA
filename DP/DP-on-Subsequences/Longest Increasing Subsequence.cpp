// Memoization TC : O(N ^ 2), SC : O(N ^ 2)
class Solution {
    int dfs(int i, int preIdx, int n, vector<int> &nums, vector<vector<int>> &dp) {
        if(i == n) return 0;
        if(dp[i][preIdx + 1] != -1) return dp[i][preIdx + 1];

        int notPick = dfs(i + 1, preIdx, n, nums, dp), pick = 0;
        if(preIdx == -1 || nums[preIdx] < nums[i]) pick = 1 + dfs(i + 1, i, n, nums, dp);
        
        return dp[i][preIdx + 1] = max(pick, notPick);
    }
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(n + 1, -1));
        return dfs(0, -1, n, nums, dp);
    }
};

// Tabulation TC : O(N ^ 2), SC : O(N ^ 2)
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n + 1, vector<int>(n + 1));

        for(int i=n-1; i>=0; i--) {
            for(int preIdx=-1; preIdx<i; preIdx++) {
                int notPick = dp[i + 1][preIdx + 1], pick = 0;
                if(preIdx == -1 || nums[preIdx] < nums[i]) pick = 1 + dp[i + 1][i + 1];
            
                dp[i][preIdx + 1] = max(pick, notPick);
            }
        }
        return dp[0][0];
    }
};

// Space Optimization TC : O(N ^ 2), SC : O(N)
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n + 1), temp(n + 1);

        for(int i=n-1; i>=0; i--) {
            for(int preIdx=-1; preIdx<i; preIdx++) {
                int notPick = dp[preIdx + 1], pick = 0;
                if(preIdx == -1 || nums[preIdx] < nums[i]) pick = 1 + dp[i + 1];
            
                temp[preIdx + 1] = max(pick, notPick);
            }
            dp = temp;
        }
        return dp[0];
    }
};

// Tabulation SC : TC : O(N ^ 2), SC : O(N)
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size(), ans = 0;
        vector<int> dp(n, 1);

        for(int i=0; i<n; i++) {
            for(int prev=0; prev<i; prev++) {
                if(nums[prev] < nums[i]) dp[i] = max(dp[i], 1 + dp[prev]);
            }
            ans = max(ans, dp[i]);
        }
        return ans;
    }
};

// Binary Search TC : O(N log N), SC : O(N)
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> v;
        for(int i : nums) {
            if(!v.size() || v.back() < i) v.push_back(i);
            else if(v.back() > i) {
                int pos = lower_bound(v.begin(), v.end(), i) - v.begin();
                v[pos] = i;
            }
        }
        return v.size();
    }
};