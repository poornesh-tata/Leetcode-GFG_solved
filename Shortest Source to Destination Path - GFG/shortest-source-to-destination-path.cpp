//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int shortestDistance(int n, int m, vector<vector<int>> A, int X, int Y) {
        // code here
        queue<pair<pair<int,int>,int>>q;
        vector<vector<int>> vis(n,vector<int>(m,0));
        
        int ans=INT_MAX;
        if(A[0][0]==0) return -1;
        q.push({{0,0},0});
        vis[0][0]=1;
        
        int row[]={-1,0,1,0};
        int col[]={0,1,0,-1};
        while(!q.empty())
        {
            pair<int,int> x=q.front().first;
            int y=q.front().second;
            q.pop();
            for(int i=0;i<4;i++)
            {
                int nrow=row[i]+x.first;
                int ncol=col[i]+x.second;
                if(nrow>=0 and nrow<n and ncol>=0 and ncol<m and vis[nrow][ncol]==0 and A[nrow][ncol]==1)
                {
                    if(nrow==X and ncol==Y) ans=min(ans,y+1);
                    q.push({{nrow,ncol},y+1});
                    vis[nrow][ncol]=1;
                }
            }
        }
        if(ans==INT_MAX) return -1;
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, M, x, y;
        cin >> N >> M;
        vector<vector<int>> v(N, vector<int>(M));
        for (int i = 0; i < N; i++)
            for (int j = 0; j < M; j++) cin >> v[i][j];
        cin >> x >> y;
        Solution ob;
        cout << ob.shortestDistance(N, M, v, x, y) << "\n";
    }
}
// } Driver Code Ends