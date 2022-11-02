class Solution {
public:
    bool bfs(vector<int> adj[],int source,int destination,vector<int> &vis)
    {
        queue<int> q;
        q.push(source);
        vis[source]=1;
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
                    if(it==destination) return true;
                }
            }
        }
        return false;
    }
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        if(source==destination) return true;
        vector<int> adj[n];
        vector<int> vis(n,0);
        for(auto it:edges)
        {
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        return bfs(adj,source,destination,vis);
    }
};