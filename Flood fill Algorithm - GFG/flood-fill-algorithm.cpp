//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
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

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>image(n, vector<int>(m,0));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++)
				cin >> image[i][j];
		}
		int sr, sc, newColor;
		cin >> sr >> sc >> newColor;
		Solution obj;
		vector<vector<int>> ans = obj.floodFill(image, sr, sc, newColor);
		for(auto i: ans){
			for(auto j: i)
				cout << j << " ";
			cout << "\n";
		}
	}
	return 0;
}
// } Driver Code Ends