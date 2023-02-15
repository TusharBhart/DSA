/*You are required to complete this method*/

class Solution{
    int getMaxArea(vector<int> &arr, int n) {
        vector<int> l2r(n), r2l(n);
        stack<pair<int, int>> s1, s2;
        
        for(int i=0; i<n; i++) {
            while(s1.size() && s1.top().first >= arr[i]) s1.pop();
            l2r[i] = s1.size() ? s1.top().second : -1;
            s1.push({arr[i], i});
        }
        
        for(int i=n-1; i>=0; i--) {
            while(s2.size() && s2.top().first >= arr[i]) s2.pop();
            r2l[i] = s2.size() ? s2.top().second : n;
            s2.push({arr[i], i});
        }
        
        int ans = 0;
        for(int i=0; i<n; i++) {
            int a = r2l[i], b = l2r[i];
            ans = max(ans, arr[i] * (a - b - 1));
        }
        return ans;
    }
  public:
    int maxArea(int M[MAX][MAX], int n, int m) {
        vector<int> v(m);
        int ans = 0;
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(!M[i][j]) v[j] = 0;
                else v[j]++;
            }
            ans = max(ans, getMaxArea(v, m));
        }
        return ans;
    }
};