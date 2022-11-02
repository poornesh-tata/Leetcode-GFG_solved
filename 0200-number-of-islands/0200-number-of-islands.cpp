class Solution {
private:
    void bfs(vector<vector<char>>& grid,vector<vector<int>>&vis,int row,int col)
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
                if(i==0) continue;
                if(ncol+i>=0 and ncol+i<m and grid[nrow][ncol+i]=='1' and vis[nrow][ncol+i]==0)
                {
                    q.push({nrow,ncol+i});
                    vis[nrow][ncol+i]=1;
                }
                if(nrow+i>=0 and nrow+i<n and grid[nrow+i][ncol]=='1' and vis[nrow+i][ncol]==0)
                {
                    q.push({nrow+i,ncol});
                    vis[nrow+i][ncol]=1;
                }
            }
        }
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int count=0;
        vector<vector<int>>vis(n,vector<int>(m,0));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(vis[i][j]==0 and grid[i][j]=='1')
                {
                    count++;
                    bfs(grid,vis,i,j);
                }
            }
        }
        return count;
    }
};