//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    public:
    //Function to find unit area of the largest region of 1s.
    void bfs(vector<vector<int>>& grid,vector<vector<int>>&vis,int row,int col,int &max)
    {
        int count=0;
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
            count++;
            for(int i=-1;i<=1;i++)
            {
                for(int j=-1;j<=1;j++)
                {
                    if(nrow+i>=0 and nrow+i<n and ncol+j>=0 and ncol+j<m 
                        and grid[nrow+i][ncol+j]==1 and vis[nrow+i][ncol+j]==0) 
                    {
                        q.push({nrow+i,ncol+j});
                        vis[nrow+i][ncol+j]=1;
                    }
                }
            }
        }
        if(count>max) max=count;
    }
    int findMaxArea(vector<vector<int>>& grid) {
        // Code here
        int n=grid.size();
        int m=grid[0].size();
        int max=0;
        vector<vector<int>>vis(n,vector<int>(m,0));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(vis[i][j]==0 and grid[i][j]==1)
                {
                    bfs(grid,vis,i,j,max);
                }
            }
        }
        return max;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>grid(n, vector<int>(m, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		int ans = obj.findMaxArea(grid);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends