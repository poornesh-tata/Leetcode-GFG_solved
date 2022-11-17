class Solution {
public:
    void bfs(int node,vector<int>& vis,vector<vector<int>>& rooms)
    {
        queue<int> q;
        q.push(node);
        vis[node]=1;
        while(!q.empty())
        {
            int x=q.front();
            q.pop();
            for(auto it:rooms[x])
            {
                if(!vis[it])
                {
                    q.push(it);
                    vis[it]=1;
                }
            }
        }
    }
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n=rooms.size();
        vector<int> vis(n,0);
        vis[0]=1;
        bfs(0,vis,rooms);
        for(auto it:vis) 
        {
            if(it==0) return false;
        }
        return true;
    }
};