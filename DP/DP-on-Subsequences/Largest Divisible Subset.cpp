class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size(), idx = 0, mx = 0;
        vector<int> dp(n, 1), track(n), ans;

        for(int i=0; i<n; i++) {
            track[i] = i;
            for(int pre=0; pre<i; pre++) {
                if(nums[i] % nums[pre] == 0) {
                    if(dp[i] < 1 + dp[pre]) {
                        dp[i] = 1 + dp[pre];
                        track[i] = pre;
                    }
                }
            }
            if(dp[i] > mx) mx = dp[i], idx = i;
        }
        while(true) {
            ans.push_back(nums[idx]);
            if(track[idx] == idx) break;
            idx = track[idx];
        }
        return ans;
    }
};