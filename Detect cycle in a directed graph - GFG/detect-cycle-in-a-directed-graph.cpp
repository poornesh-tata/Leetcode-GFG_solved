//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in a directed graph.
    bool dfs(int i,int V,vector<int> adj[],vector<int>&vis,vector<int>&pvis)
    {
        vis[i]=1;
        pvis[i]=1;
        for(auto it:adj[i])
        {
            if(!vis[it])
            {
                if(dfs(it,V,adj,vis,pvis)) return true;
            }
            else if(vis[it]==1 and pvis[it]==1) return true;
        }
        pvis[i]=0;
        return false;
    }
    bool isCyclic(int V, vector<int> adj[]) {
        // code here
        vector<int> vis(V+1,0);
        vector<int> pvis(V+1,0);
        for(int i=0;i<V;i++)
        {
            if(!vis[i])
            {
                if(dfs(i,V,adj,vis,pvis)) return true;
            }
        }
        return false;
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}

// } Driver Code Ends