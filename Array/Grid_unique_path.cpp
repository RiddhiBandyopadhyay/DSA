//Approach-1 (DP)
class Solution {
public:
    int uniquePaths(int m, int n) {
    int dp[m][n];
        
    for (int i = 0; i < m; i++){
        for (int j = 0; j < n; j++){
            if (i == 0 or j == 0)
                dp[i][j] = 1;
            else
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            }   
        }
        return dp[m - 1][n - 1];
    }
};

//Approach-2 (Combination formula based)
class Solution {
public:
    int uniquePaths(int m, int n) {
        int N = m+n-2;
        int r = m-1;
        double ans=1.0;
        
        for(int i=1;i<=r;i++){
            ans = ans*(N - r + i)/i;
        }
        return (int)ans;
    }
};
