//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
    public:
    //Function to find whether a path exists from the source to destination.
    int dfs(vector<vector<int>>& grid,vector<vector<int>>& vis,int sr,int sc,int row[],int col[])
    {
        int ans=0;
        int n=grid.size();
        int m=grid[0].size();
        queue<pair<int,int>> q;
        q.push({sr,sc});
        vis[sr][sc]=1;
        while(!q.empty())
        {
            int r=q.front().first;
            int c=q.front().second;
            q.pop();
            for(int i=0;i<4;i++)
            {
                int nrow=r+row[i];
                int ncol=c+col[i];
                if(nrow>=0 and nrow<n and ncol>=0 and ncol<m and grid[nrow][ncol]!=0 and vis[nrow][ncol]==0)
                {
                    if(grid[nrow][ncol]==2) return 1;
                    vis[nrow][ncol]=1;
                    ans=dfs(grid,vis,nrow,ncol,row,col);
                    if(ans==1) return ans;
                }
            }
        }
        return ans;
    }
    bool is_Possible(vector<vector<int>>& grid) 
    {
        //code here
        int sr,sc;
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==1)
                {
                    sr=i;
                    sc=j;
                }
            }
        }
        int row[]={-1,0,1,0};
        int col[]={0,1,0,-1};
        return dfs(grid,vis,sr,sc,row,col)?true:false;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<vector<int>>grid(n, vector<int>(n, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		bool ans = obj.is_Possible(grid);
		cout << ((ans) ? "1\n" : "0\n");
	}
	return 0;
}
// } Driver Code Ends