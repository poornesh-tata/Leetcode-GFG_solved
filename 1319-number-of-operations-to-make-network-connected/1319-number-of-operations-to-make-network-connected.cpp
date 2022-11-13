class Solution {
public:
    void bfs(int node,vector<int> adj[],vector<int>&vis)
    {
        queue<int> q;
        q.push(node);
        vis[node]=1;
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
                }
            }
        }
    }
    int makeConnected(int n, vector<vector<int>>& connections) {
        if(connections.size()+1<n) return -1;
        int count=0;
        vector<int> adj[n];
        vector<int> vis(n,0);
        for(auto it:connections)
        {
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        for(int i=0;i<n;i++)
        {
            if(!vis[i])
            {
                count++;
                bfs(i,adj,vis);
            }
        }
        return count-1;
    }
};