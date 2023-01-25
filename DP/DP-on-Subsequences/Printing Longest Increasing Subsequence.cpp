class Solution {
  public:
    vector<int> longestIncreasingSubsequence(int n, vector<int>& arr) {
        int idx = 0, mx = 0;
        vector<int> dp(n, 1), track(n), ans;
        for(int i=0; i<n; i++) track[i] = i;
        
        for(int i=0; i<n; i++) {
            for(int prev=0; prev<i; prev++) {
                if(arr[prev] < arr[i]) {
                    if(dp[i] < 1 + dp[prev]) dp[i] = 1 + dp[prev], track[i] = prev;
                }
            }
            if(mx < dp[i]) mx = dp[i], idx = i;
        }
        
        while(1) {
            ans.push_back(arr[idx]);
            if(idx == track[idx]) break;
            idx = track[idx];
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};