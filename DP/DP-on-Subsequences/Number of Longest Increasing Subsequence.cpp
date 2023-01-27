class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n = nums.size(), ans = 0, lis = 0;
        vector<int> dp(n, 1), cnt(n, 1);

        for(int i=0; i<n; i++) {
            for(int pre=0; pre<i; pre++) {
                if(nums[pre] < nums[i]) {
                    if(dp[i] < dp[pre] + 1) cnt[i] = cnt[pre], dp[i] = dp[pre] + 1;
                    else if(dp[i] == dp[pre] + 1) cnt[i] += cnt[pre];
                }
            }
            lis = max(lis, dp[i]);
        }
        for(int i=0; i<n; i++) {
            if(dp[i] == lis) ans += cnt[i];
        }
        return ans; 
    }
};