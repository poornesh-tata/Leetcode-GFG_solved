class Solution {
private:
    void bfs(vector<int>& vis,int i,vector<int> adj[])
    {
        queue<int> q;
        q.push(i);
        vis[i]=1;
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
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int count=0;
        int n=isConnected.size();
        vector<int> adj[n];
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<isConnected[0].size();j++)
            {
                if(i!=j and isConnected[i][j]==1) 
                {
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }
        vector<int> vis(n+1,0);
        for(int i=0;i<n;i++)
        {
            if(!vis[i])
            {
                count++;
                bfs(vis,i,adj);
            }
        }
        return count;
    }
};