//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    void bfs(vector<vector<char>> board,vector<vector<char>>&ans,vector<vector<int>>&vis,int r,int c,int row[],int col[])
    {
        int n=board.size();
        int m=board[0].size();
        queue<pair<int,int>> q;
        q.push({r,c});
        vis[r][c]=1;
        ans[r][c]='O';
        while(!q.empty())
        {
            int x=q.front().first;
            int y=q.front().second;
            q.pop();
            for(int i=0;i<4;i++)
            {
                int nrow=x+row[i];
                int ncol=y+col[i];
                if(nrow>=0 and ncol>=0 and nrow<n and ncol<m and board[nrow][ncol]=='O' and vis[nrow][ncol]==0)
                {
                    ans[nrow][ncol]='O';
                    vis[nrow][ncol]=1;
                    q.push({nrow,ncol});
                }
            }
        }
    }
    vector<vector<char>> fill(int n, int m, vector<vector<char>> board)
    {
        vector<vector<char>> ans(n,vector<char>(m,'X'));
        vector<vector<int>> vis(n,vector<int>(m,0));
        int row[]={-1,0,1,0};
        int col[]={0,1,0,-1};
        for(int i=0;i<m;i++)
        {
            if(board[0][i]=='O'  and vis[0][i]==0)
            {
                bfs(board,ans,vis,0,i,row,col);
            }
            if(board[n-1][i]=='O' and vis[n-1][i]==0)
            {
                bfs(board,ans,vis,n-1,i,row,col);
            }
        }
        for(int i=0;i<n;i++)
        {
            if(board[i][0]=='O' and vis[i][0]==0)
            {
                bfs(board,ans,vis,i,0,row,col);
            }
            if(board[i][m-1]=='O' and vis[i][m-1]==0)
            {
                bfs(board,ans,vis,i,m-1,row,col);
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, m;
        cin>>n>>m;
        vector<vector<char>> mat(n, vector<char>(m, '.'));
        for(int i = 0;i < n;i++)
            for(int j=0; j<m; j++)
                cin>>mat[i][j];
        
        Solution ob;
        vector<vector<char>> ans = ob.fill(n, m, mat);
        for(int i = 0;i < n;i++) {
            for(int j = 0;j < m;j++) {
                cout<<ans[i][j]<<" ";
            }
            cout<<"\n";
        }
    }
    return 0;
}
// } Driver Code Ends