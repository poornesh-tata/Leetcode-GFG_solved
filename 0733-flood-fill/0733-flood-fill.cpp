class Solution {
public:
    void dfs(vector<vector<int>>& image,vector<vector<int>> &grid,int sr,int sc,int newColor,int startColor,int row[],int col[])
    {
        int n=grid.size();
        int m=grid[0].size();
        grid[sr][sc]=newColor;
        for(int i=0;i<4;i++)
        {
            int nrow=sr+row[i];
            int ncol=sc+col[i];
            if(nrow>=0 and nrow<n and ncol>=0 and ncol<m and image[nrow][ncol]==startColor 
             and grid[nrow][ncol]!=newColor)
            {
                grid[nrow][ncol]=newColor;
                dfs(image,grid,nrow,ncol,newColor,startColor,row,col);
            }
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        vector<vector<int>> grid=image;
        int startColor=grid[sr][sc];
        int row[]={-1,0,1,0};
        int col[]={0,1,0,-1};
        dfs(image,grid,sr,sc,newColor,startColor,row,col);
        return grid;
    }
};