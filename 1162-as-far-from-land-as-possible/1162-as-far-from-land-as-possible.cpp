class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));
        vector<vector<int>> dis(n,vector<int>(m,0));
        queue<pair<pair<int,int>,int>> q;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]==1)
                {
                    q.push({{i,j},0});
                    vis[i][j]=1;
                }
            }
        }
        int ans=INT_MIN;
        int row[]={-1,0,1,0};
        int col[]={0,1,0,-1};
        while(!q.empty())
        {
            pair<int,int> x=q.front().first;
            int y=q.front().second;
            q.pop();
            for(int i=0;i<4;i++)
            {
                int nrow=x.first+row[i];
                int ncol=x.second+col[i];
                if(nrow>=0 and ncol>=0 and nrow<n and ncol<m and vis[nrow][ncol]==0 and grid[nrow][ncol]==0)
                {
                    if(y+1>ans) ans=y+1;
                    q.push({{nrow,ncol},y+1});
                    vis[nrow][ncol]=1;
                }
            }
        }
        return ans==INT_MIN?-1:ans;
    }
};