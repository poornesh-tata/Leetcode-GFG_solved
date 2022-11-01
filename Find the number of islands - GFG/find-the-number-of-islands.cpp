//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
      public:
    // Function to find the number of islands.
    void bfs(vector<vector<char>>& grid,vector<vector<int>> &vis,int row,int col)
    {
        int n=grid.size();
        int m=grid[0].size();
        queue<pair<int,int>> q;
        q.push({row,col});
        vis[row][col]=1;
        while(!q.empty())
        {
            int nrow=q.front().first;
            int ncol=q.front().second;
            q.pop();
            for(int i=-1;i<=1;i++)
            {
                for(int j=-1;j<=1;j++)
                {
                    if(nrow+i<n and ncol+j<m and nrow+i>=0 and ncol+j>=0 and vis[nrow+i][ncol+j]==0 and grid[nrow+i][ncol+j]=='1')
                    {
                        q.push({nrow+i,ncol+j});
                        vis[nrow+i][ncol+j]=1;
                    }
                }
            } 
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        // Code here
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>> vis( n , vector<int> (m, 0));
        int count=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]=='1' and vis[i][j]==0)
                {
                    bfs(grid,vis,i,j);
                    count++;
                }
            }
        }
        return count;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<char>> grid(n, vector<char>(m, '#'));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        int ans = obj.numIslands(grid);
        cout << ans << '\n';
    }
    return 0;
}
// } Driver Code Ends