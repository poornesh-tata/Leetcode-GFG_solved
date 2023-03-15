//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution {
    public:
    bool isvalid(int i,int j,vector<vector<int>>& matrix)
    {
        int n=matrix.size();
        int m=matrix[0].size();
        if(i<0 or j<0 or i>=n or j>=m) return false;
        return true;
    }
    void dfs(int i,int j,vector<vector<int>>& matrix,vector<vector<int>>& vis,int row[],int col[])
    {
        if(vis[i][j]) return ;
        vis[i][j]=1;
        for(int z=0;z<4;z++)
        {
            int nrow=i+row[z];
            int ncol=j+col[z];
            if(isvalid(nrow,ncol,matrix) and !vis[nrow][ncol] and matrix[nrow][ncol]==1)
            {
                dfs(nrow,ncol,matrix,vis,row,col);
            }
        }
    }
    int closedIslands(vector<vector<int>>& matrix, int n, int m) {
        // Code here
        int count=0; vector<vector<int>> vis(n,vector<int>(m,0));
        int row[]={-1,0,1,0};
        int col[]={0,1,0,-1};
        
        for(int i=0;i<n;i++)
        {
            if(matrix[i][0]==1) dfs(i,0,matrix,vis,row,col);
            if(matrix[i][m-1]==1) dfs(i,m-1,matrix,vis,row,col);
        }
        for(int i=0;i<m;i++)
        {
            if(matrix[0][i]==1) dfs(0,i,matrix,vis,row,col);
            if(matrix[n-1][i]==1) dfs(n-1,i,matrix,vis,row,col);
        }
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(matrix[i][j]==1 and !vis[i][j])
                {
                    dfs(i,j,matrix,vis,row,col);
                    count++;
                }
            }
        }

        return count;
    }
};

//{ Driver Code Starts.
int main() {
	int t;
	cin>>t;
	while(t--)
	{
        int N, M;
        cin >> N >> M;
        vector<vector<int>>matrix(N, vector<int>(M, 0));
        for(int i=0; i<N; i++)
            for(int j=0; j<M; j++)
                cin >> matrix[i][j];
                
        Solution obj;
        int ans = obj.closedIslands(matrix, N, M);
        cout << ans << "\n";
    }
	
	return 0;
	
}


// } Driver Code Ends