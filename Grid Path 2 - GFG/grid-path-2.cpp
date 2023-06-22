//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    long long mod = 1e9+7;
    int fun(int i, int j, int a, int b, vector<vector<int>>& dp, vector<vector<int>>& grid)
    {
        if(i==a-1 and j==b-1 ) 
        {
            if(grid[i][j]==1) return 0;
            dp[i][j]=1;
            return 1;
        }
        if(i>=a or j>=b) return 0;
        if(grid[i][j]==1) return 0;
        
        int x,y;
        if(dp[i+1][j]!=-1) x = dp[i+1][j];
        else x = fun(i+1,j,a,b,dp,grid);
        if(dp[i][j+1]!=-1) y = dp[i][j+1];
        else y = fun(i,j+1,a,b,dp,grid);
        
        return dp[i][j] = (x%mod + y%mod)%mod;
    }
    int totalWays(int n, int m, vector<vector<int>>& grid) {
        // Code here
        vector<vector<int>> dp(n+1,vector<int>(m+1,-1));
        return fun(0,0,n,m,dp,grid);
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid;
        for (int i = 0; i < n; ++i) {
            vector<int> temp;
            for (int i = 0; i < m; ++i) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            grid.push_back(temp);
        }

        Solution obj;
        cout << obj.totalWays(n, m, grid) << "\n";
    }
    return 0;
}
// } Driver Code Ends