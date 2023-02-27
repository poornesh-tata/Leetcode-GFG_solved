//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    void dfs(int i,vector<vector<int>>& adj,vector<int> &vis,int &n,int &e)
    {
        vis[i]=1;
        n++;
        e+=adj[i].size();
        for(auto &it:adj[i])
        {
           if(!vis[it])
           {
                dfs(it,adj,vis,n,e);
           }
        }
    }
    int findNumberOfGoodComponent(int V, vector<vector<int>>& adj) {
        // code here
        int ans=0;
        vector<int> vis(V+1,0);
        for(int i=1;i<=V;i++)
        {
            if(!vis[i])
            {
                int n=0,e=0;
                dfs(i,adj,vis,n,e);
                n=(n*(n-1))/2;
                e=e/2;
                // cout<<i<<" "<<n<<" "<<e<<endl;
                if(e == n)
                {
                    ans++;
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
        int E, V;
        cin >> E >> V;
        vector<vector<int>> adj(V + 1, vector<int>());
        for (int i = 0; i < E; i++) {
            int u, v;

            cin >> u >> v;

            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;

        int res = obj.findNumberOfGoodComponent(V, adj);
        cout << res << "\n";
    }
    return 0;
}
// } Driver Code Ends