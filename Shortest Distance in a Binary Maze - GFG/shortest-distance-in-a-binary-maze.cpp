//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int bfs(vector<vector<int>>&grid,vector<vector<int>>&vis,pair<int, int> s,
                     pair<int, int> d,int row[],int col[])
    {
        int ans=INT_MAX;
        int n=grid.size();
        int m=grid[0].size();
        queue<pair<pair<int,int>,int>>q;
        q.push({{d.first,d.second},0});
        vis[d.first][d.second]=1;
        while(!q.empty())
        {
            pair<int,int> x=q.front().first;
            int y=q.front().second;
            q.pop();
            for(int i=0;i<4;i++)
            {
                int nrow=x.first+row[i];
                int ncol=x.second+col[i];
                if(nrow>=0 and nrow<n and ncol>=0 and ncol<m and vis[nrow][ncol]==0 and grid[nrow][ncol]==1)
                {
                    if(nrow==s.first and ncol==s.second)
                    {
                        if(ans>y+1) ans=y+1;
                    }
                    q.push({{nrow,ncol},y+1});
                    vis[nrow][ncol]=1;
                }
            }
        }
        return ans;
    }
    int shortestPath(vector<vector<int>> &grid, pair<int, int> source,
                     pair<int, int> destination) {
        if(source==destination) return 0;
        int n=grid.size();
        int m=grid[0].size();
        if(grid[destination.first][destination.second]==0 or grid[source.first][source.second]==0) return -1;
        if(n==1 and m==1 and grid[0][0]==1) return 0;
        vector<vector<int>> vis(n,vector<int>(m,0));
        int row[]={-1,0,1,0};
        int col[]={0,1,0,-1};
        int x=bfs(grid,vis,source,destination,row,col);
        if(x==INT_MAX) return -1;
        return x;
    }
};


//{ Driver Code Starts.
int main() {

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }

        pair<int, int> source, destination;
        cin >> source.first >> source.second;
        cin >> destination.first >> destination.second;
        Solution obj;
        cout << obj.shortestPath(grid, source, destination) << endl;
    }
}

// } Driver Code Ends