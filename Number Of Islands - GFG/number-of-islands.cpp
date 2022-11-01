//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
  void bfs(vector<vector<int>>& grid,vector<vector<int>>&vis,int row,int col)
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
                if(ncol+i>=0 and ncol+i<m and grid[nrow][ncol+i]==1 and vis[nrow][ncol+i]==0)
                {
                    q.push({nrow,ncol+i});
                    vis[nrow][ncol+i]=1;
                }
                if(nrow+i>=0 and nrow+i<n and grid[nrow+i][ncol]==1 and vis[nrow+i][ncol]==0)
                {
                    q.push({nrow+i,ncol});
                    vis[nrow+i][ncol]=1;
                }
            }
        }
    }
    int numIslands(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int count=0;
        vector<vector<int>>vis(n,vector<int>(m,0));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(vis[i][j]==0 and grid[i][j]==1)
                {
                    count++;
                    bfs(grid,vis,i,j);
                }
            }
        }
        return count;
    }
    vector<int> numOfIslands(int n, int m, vector<vector<int>> &operators) {
        // code here
        vector<int> ans;
        vector<vector<int>> mat(n,vector<int>(m,0));
        int x=operators[0][0],y=operators[0][1];
        mat[x][y]=1;
        ans.push_back(1);
        for(int i=1;i<operators.size();i++)
        {
            x=operators[i][0];
            y=operators[i][1];
            mat[x][y]=1;
            int z=numIslands(mat);
            ans.push_back(z);
        }
        return ans;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n,m,k; cin>>n>>m>>k;
        vector<vector<int>> a;
        
        for(int i=0; i<k; i++){
            vector<int> temp;
            for(int j=0; j<2; j++){
                int x; cin>>x;
                temp.push_back(x);
            }
            a.push_back(temp);
        }
    
        Solution obj;
        vector<int> res = obj.numOfIslands(n,m,a);
        
        for(auto x : res)cout<<x<<" ";
        cout<<"\n";
    }
}

// } Driver Code Ends