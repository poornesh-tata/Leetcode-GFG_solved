//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution
{
    public:
    //Function to find the number of 'X' total shapes.
    bool isvalid(int i,int j,vector<vector<char>>& grid)
    {
        int n=grid.size();
        int m=grid[0].size();
        if(i<0 or j<0 or i>=n or j>=m) return false;
        return true;
    }
    void dfs(int i,int j,vector<vector<char>>& grid,vector<vector<int>>& vis,int row[],int col[])
    {
        vis[i][j]=1;
        for(int z=0;z<4;z++)
        {
            int nrow=i+row[z];
            int ncol=j+col[z];
            if(isvalid(nrow,ncol,grid) and !vis[nrow][ncol] and grid[nrow][ncol]=='X')
            {
                dfs(nrow,ncol,grid,vis,row,col);
            }
        }
    }
    int xShape(vector<vector<char>>& grid) 
    {
        // Code here
        int count=0; int n=grid.size(); int m=grid[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));
        int row[]={-1,0,1,0};
        int col[]={0,1,0,-1};
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]=='X' and !vis[i][j])
                {
                    dfs(i,j,grid,vis,row,col);
                    count++;
                }
            }
        }
        return count;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<char>>grid(n, vector<char>(m, '#'));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		int ans = obj.xShape(grid);
		cout << ans <<'\n';
	}
	return 0;
}
// } Driver Code Ends