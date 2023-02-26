//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int count(int i,vector<vector<int>>& adj,vector<int> vis)
    {
        vis[i]=1;
        int c=1;
        queue<int>q;
        q.push(i);
        while(!q.empty())
        {
            int x=q.front();
            q.pop();
            for(auto it:adj[x])
            {
                if(!vis[it])
                {
                    q.push(it);
                    vis[it]=1;
                    c++;
                }
            }
        }
        return c;
    }
    bool bfs(int i,int c,vector<vector<int>>& adj,vector<int> &vis)
    {
        bool ans=true;
        vis[i]=1;
        queue<int>q;
        q.push(i);
        while(!q.empty())
        {
            int x=q.front();
            q.pop();
            for(auto it:adj[x])
            {
                if(!vis[it])
                {
                    vis[it]=1;
                    if(adj[it].size()!=c-1)
                    {
                        ans=false;
                    }
                    q.push(it);
                }
            }
        }
        return ans;
    }
    int findNumberOfGoodComponent(int V, vector<vector<int>>& adj) {
        // code here
        int n=adj.size(); int ans=0,c=0;
        vector<int> vis(n,0);
        // cout<<n<<endl;
        
        for(int i=1;i<n;i++)
        {
            // cout<<i<<" "<<vis[i]<<endl;
            if(!vis[i])
            {
                c=count(i,adj,vis);
                // cout<<i<<"->"<<c<<endl;
                if(bfs(i,c,adj,vis)) ans++;
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