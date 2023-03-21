//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    bool isvalid(int n,int m,int row,int col)
    {
        if(row<0 or col<0 or row>=n or col>=m) return false;
        return true;
    }
    int distance(int x,int y,int nrow, int ncol)
    {
        return abs(x-nrow)+abs(y-ncol);
    }
    int shortestXYDist(vector<vector<char>> grid, int n, int m) {
        queue<pair<pair<int,int>,pair<int,int>>> q; int ans=INT_MAX;
        
        vector<vector<int>> vis(n,vector<int>(m,0));
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]=='X') q.push({{i,j},{i,j}});
            }
        }
        int row[]={-1,0,1,0};
        int col[]={0,1,0,-1};
        while(!q.empty())
        {
            auto a=q.front().first;
            auto b=q.front().second;
            q.pop();
            for(int i=0;i<4;i++)
            {
                int nrow=b.first+row[i];
                int ncol=b.second+col[i];
                if(isvalid(n,m,nrow,ncol) and !vis[nrow][ncol])
                {
                    if(grid[nrow][ncol]=='Y')
                    {
                        ans=min(ans,distance(a.first,a.second,nrow,ncol));
                        break;
                    }
                    else
                    {
                        q.push({{a.first,a.second},{nrow,ncol}});
                        vis[nrow][ncol]=1;
                    }
                }
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, M;
        char ch;
        cin >> N >> M;

        vector<vector<char>> grid;

        for (int i = 0; i < N; i++) {
            vector<char> col;
            for (int i = 0; i < M; i++) {
                cin >> ch;
                col.push_back(ch);
            }
            grid.push_back(col);
        }

        Solution ob;
        cout << ob.shortestXYDist(grid, N, M) << endl;
    }
    return 0;
}
// } Driver Code Ends