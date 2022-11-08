class Solution {
public:
    void bfs(vector<vector<int>> &grid,vector<vector<int>>&vis,int r,int c,int row[],int col[])
    {
        int n=grid.size();
        int m=grid[0].size();
        queue<pair<int,int>> q;
        q.push({r,c});
        vis[r][c]=1;
        while(!q.empty())
        {
            int x=q.front().first;
            int y=q.front().second;
            q.pop();
            for(int i=0;i<4;i++)
            {
                int nrow=x+row[i];
                int ncol=y+col[i];
                if(nrow>=0 and ncol>=0 and nrow<n and ncol<m and grid[nrow][ncol]==1 and vis[nrow][ncol]==0)
                {
                    q.push({nrow,ncol});
                    vis[nrow][ncol]=1;
                }
            }
        }
    }
    int numEnclaves(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int count=0;
        vector<vector<int>> vis(n,vector<int>(m,0));
        int row[]={-1,0,1,0};
        int col[]={0,1,0,-1};
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(i==0 or i==n-1 or j==0 or j==m-1)
                {
                    if(!vis[i][j] and grid[i][j]==1)
                    {
                        bfs(grid,vis,i,j,row,col);
                    }
                }
            }
        }
        int c=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(vis[i][j]==0 and grid[i][j]==1)
                {
                    c++;
                }
            }
        }
        return c;
    }
};