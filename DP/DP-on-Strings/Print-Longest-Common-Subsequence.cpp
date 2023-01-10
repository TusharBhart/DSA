#include<bits/stdc++.h>
using namespace std;

string printLCS(string &s, string &t) {
    int n = s.size(), m = t.size();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1));

    for(int i=1; i<=n; i++) {
        for(int j=1; j<=m; j++) {
            if(s[i - 1] == t[j - 1]) dp[i][j] = 1 + dp[i - 1][j - 1];
            else dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }
    
    string ans;
    int i = n, j = m;
    while(i && j) {
        if(s[i - 1] == t[j - 1]) {
            ans += s[i  - 1];
            i--, j--;
        }
        else if(dp[i - 1][j] > dp[i][j - 1]) i--;
        else j--;
    }
    
    reverse(ans.begin(), ans.end());
    return ans;
}

int main() {
    string s = "abcde", t = "bdqek";
    string ans = printLCS(s, t);
    cout << ans;
    return 0;
}