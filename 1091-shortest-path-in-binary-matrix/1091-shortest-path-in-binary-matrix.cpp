class Solution {
public:
    int bfs(vector<vector<int>>&grid,vector<vector<int>>&vis)
    {
        int ans=INT_MAX;
        int n=grid.size();
        queue<pair<pair<int,int>,int>>q;
        q.push({{n-1,n-1},0});
        vis[n-1][n-1]=1;
        while(!q.empty())
        {
            pair<int,int> x=q.front().first;
            int y=q.front().second;
            q.pop();
            for(int i=-1;i<=1;i++)
            {
                for(int j=-1;j<=1;j++)
                {
                    int nrow=x.first+i;
                    int ncol=x.second+j;
                    if(nrow>=0 and nrow<n and ncol>=0 and ncol<n and vis[nrow][ncol]==0 and grid[nrow][ncol]==0)
                    {
                        if(nrow==0 and ncol==0)
                        {
                            if(ans>y+1) ans=y+1;
                        }
                        q.push({{nrow,ncol},y+1});
                        vis[nrow][ncol]=1;
                    }
                }
            }
        }
        return ans;
    }
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n=grid.size();
        if(grid[n-1][n-1]==1 or grid[0][0]==1) return -1;
        if(n==1 and grid[0][0]==0) return 1;
        vector<vector<int>> vis(n,vector<int>(n,0));
        int x=bfs(grid,vis);
        if(x==INT_MAX) return -1;
        return x+1;
    }
};