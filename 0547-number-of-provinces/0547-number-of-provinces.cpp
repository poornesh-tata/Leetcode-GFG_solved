class Solution {
private:
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
                dfs(vis,i,adj);
            }
        }
        return count;
    }
};