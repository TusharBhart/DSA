// MEMOIZATION
class Solution {
    bool dfs(int i, int t, vector<int> &nums, vector<vector<int>> &dp) {
        if(!t) return true;
        if(!i) return nums[0] == t;
        if(dp[i][t] != -1) return dp[i][t];
        
        bool notTake = dfs(i - 1, t, nums, dp);
        bool take = t >= nums[i] ? dfs(i - 1, t - nums[i], nums, dp) : false;

        return dp[i][t] = take || notTake;
    }
public:
    bool canPartition(vector<int>& nums) {
        int t = 0, n = nums.size();
        for(int i : nums) t += i;

        if(t % 2) return false;
        t /= 2;

        vector<vector<int>> dp(n, vector<int>(t + 1, -1)); 
        return dfs(n - 1, t, nums, dp); 
    }
};

// TABULATION
class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = 0, n = nums.size();
        for(int i : nums) sum += i;

        if(sum % 2) return false;
        sum /= 2;

        vector<vector<bool>> dp(n, vector<bool>(sum + 1));  

        for(int i=0; i<n; i++) dp[i][0] = true;
        if(nums[0] <= sum) dp[0][nums[0]] = true;

        for(int i=1; i<n; i++) {
            for(int t=1; t<=sum; t++) {
                bool notTake = dp[i - 1][t];
                bool take = t >= nums[i] ? dp[i - 1][t - nums[i]] : false;
                dp[i][t] = take || notTake;
            }
        }
        return dp[n - 1][sum];
    }
};

// SPACE OPTIMIZATION
class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = 0, n = nums.size();
        for(int i : nums) sum += i;

        if(sum % 2) return false;
        sum /= 2;

        vector<bool> dp(sum + 1), temp(sum + 1); 

        dp[0] = true;
        if(nums[0] <= sum) dp[nums[0]] = true;

        for(int i=1; i<n; i++) {
            for(int t=1; t<=sum; t++) {
                bool notTake = dp[t];
                bool take = t >= nums[i] ? dp[t - nums[i]] : false;
                temp[t] = take || notTake;
            }
            dp = temp;
        }
        return dp[sum];
    }
};