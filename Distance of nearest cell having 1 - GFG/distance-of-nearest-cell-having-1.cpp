//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution 
{
    public:
    //Function to find distance of nearest 1 in the grid for each cell.
    void bfs(vector<vector<int>>&vis,vector<vector<int>>&dis,vector<vector<int>>table)
    {
        int n=table.size();
        int m=table[0].size();
        queue<pair<pair<int,int>,int>>q;
        for(int i=0;i<n;i++)
	    {
	        for(int j=0;j<m;j++)
	        {
	            if(table[i][j]==1)
	            {
	                vis[i][j]=1;
	                q.push({{i,j},0});
	            }
	        }
	    }
	    while(!q.empty())
	    {
	        pair<int,int> x=q.front().first;
	        int y=q.front().second;
	        dis[x.first][x.second]=y;
	        q.pop();
	        int row[]={-1,0,1,0};
	        int col[]={0,1,0,-1};
	        for(int i=0;i<4;i++)
	        {
	            int nrow=x.first+row[i];
	            int ncol=x.second+col[i];
	            if(nrow>=0 and nrow<n and ncol>=0 and ncol<m and
	                                    vis[nrow][ncol]==0 and table[nrow][ncol]==0)
	            {
	                vis[nrow][ncol]=1;
	                q.push({{nrow,ncol},y+1});
	            }
	        }
	    }
    }
	vector<vector<int>>nearest(vector<vector<int>>grid)
	{
	    // Code here
	    int n=grid.size();
        int m=grid[0].size();
	    vector<vector<int>> table=grid;
	    vector<vector<int>> vis(n,vector<int> (m,0));
	    vector<vector<int>> dis(n,vector<int>(m));
	    bfs(vis,dis,table);
	    return dis;
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
		vector<vector<int>> ans = obj.nearest(grid);
		for(auto i: ans){
			for(auto j: i){
				cout << j << " ";
			}
			cout << "\n";
		}
	}
	return 0;
}
// } Driver Code Ends