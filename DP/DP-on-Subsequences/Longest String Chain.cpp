class Solution {
    static bool cmp(string &a, string &b) {
        return a.size() < b.size();
    }
    bool good(string &s, string &t) {
        int i = 0, j = 0, n = s.size(), m = t.size();
        if(n + 1 != m) return false;

        while(j < m) {
            if(s[i] == t[j]) i++;
            j++;
        }
        return i == n && j == m;
    }
public:
    int longestStrChain(vector<string>& words) {
        sort(words.begin(), words.end(), cmp);
        int n = words.size(), ans = 0;
        vector<int> dp(n, 1);

        for(int i=0; i<n; i++) {
            for(int pre=0; pre<i; pre++) {
                if(good(words[pre], words[i])) dp[i] = max(dp[i], 1 + dp[pre]);
            }
            ans = max(ans, dp[i]);
        }
        return ans;
    }
};