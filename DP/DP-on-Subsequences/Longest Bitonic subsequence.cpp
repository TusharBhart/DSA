class Solution{
    vector<int> helper(vector<int> &nums) {
        int n = nums.size();
        vector<int> dp(n, 1);
        
        for(int i=0; i<n; i++) {
            for(int pre=0; pre<i; pre++) {
                if(nums[pre] < nums[i]) dp[i] = max(dp[i], 1 + dp[pre]);
            }
        }
        return dp;
    }
	public:
	int LongestBitonicSequence(vector<int>nums) {
	    int n = nums.size(), ans = 0;
	    vector<int> dp1 = helper(nums);
	    reverse(nums.begin(), nums.end());
	    vector<int> dp2 = helper(nums);
	    reverse(dp2.begin(), dp2.end());
	    
	    for(int i=0; i<n; i++) ans = max(ans, dp1[i] + dp2[i] - 1);
	    return ans;
	}
};