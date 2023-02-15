class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int n = matrix.size(), m = matrix[0].size(), ans = 0;
        vector<vector<int>> mat(n, vector<int>(m));
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) mat[i][j] = matrix[i][j] - '0';
        }

        for(int i=1; i<n; i++) {
            for(int j=1; j<m; j++) {
                if(mat[i][j]) mat[i][j] = min(mat[i - 1][j - 1], min(mat[i][j - 1], mat[i - 1][j])) + 1;
            }
        }
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) ans = max(ans, mat[i][j]);
        }
        return ans * ans;
    }
};