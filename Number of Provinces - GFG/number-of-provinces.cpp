//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    void dfs(vector<int>& vis,int i,vector<int> adj[])
    {
        vis[i]=1;
        for(auto it:adj[i])
        {
            if(!vis[it])
            {
                dfs(vis,it,adj);
            }
        }
    }
    int numProvinces(vector<vector<int>> adj, int V) {
        int count=0;
        int n=adj.size();
        vector<int> adjl[n];
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<adj[0].size();j++)
            {
                if(i!=j and adj[i][j]==1) 
                {
                    adjl[i].push_back(j);
                    adjl[j].push_back(i);
                }
            }
        }
        vector<int> vis(n+1,0);
        for(int i=0;i<n;i++)
        {
            if(!vis[i])
            {
                count++;
                dfs(vis,i,adjl);
            }
        }
        return count;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int V,x;
        cin>>V;
        
        vector<vector<int>> adj;
        
        for(int i=0; i<V; i++)
        {
            vector<int> temp;
            for(int j=0; j<V; j++)
            {
                cin>>x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }
        

        Solution ob;
        cout << ob.numProvinces(adj,V) << endl;
    }
    return 0;
}
// } Driver Code Ends