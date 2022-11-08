class Solution {
public:
    void bfs(vector<vector<int>> grid,vector<vector<int>>&vis,int r,int c,int row[],int col[])
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
        for(int i=0;i<m;i++)
        {
            if(grid[0][i]==1  and vis[0][i]==0)
            {
                bfs(grid,vis,0,i,row,col);
            }
            if(grid[n-1][i]==1 and vis[n-1][i]==0)
            {
                bfs(grid,vis,n-1,i,row,col);
            }
        }
        for(int i=0;i<n;i++)
        {
            if(grid[i][0]==1 and vis[i][0]==0)
            {
                bfs(grid,vis,i,0,row,col);
            }
            if(grid[i][m-1]==1 and vis[i][m-1]==0)
            {
                bfs(grid,vis,i,m-1,row,col);
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