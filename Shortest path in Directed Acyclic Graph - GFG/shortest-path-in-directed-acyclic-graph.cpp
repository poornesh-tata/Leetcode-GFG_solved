//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
     vector<int> shortestPath(int n,int M, vector<vector<int>>& edges){
        // code here
        vector < pair < int, int >> adj[n];
        for(auto it:edges)
        {
            adj[it[0]].push_back({it[1],it[2]});
        }
        vector<int> dis(n,INT_MAX);
        dis[0]=0;
        for(int i=0;i<n;i++)
        {
            for(auto it:adj[i])
            {
                if(dis[i]==INT_MAX) continue;
                // cout<<it.first<<" "<<dis[it.first]<<" ";
                dis[it.first]=min(dis[it.first],dis[i]+it.second);
                // cout<<dis[it.first]<<endl;
            }
        }
        for(int i=0;i<dis.size();i++)
        {
            if(dis[i]==INT_MAX) dis[i]=-1;
        }
        return dis;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> edges;
        for(int i=0; i<m; ++i){
            vector<int> temp;
            for(int j=0; j<3; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }
        Solution obj;
        vector<int> res = obj.shortestPath(n, m, edges);
        for (auto x : res) {
            cout << x << " ";
        }
        cout << "\n";
    }
}

// } Driver Code Ends