class Solution {
public:
    bool bfs(vector<vector<int>>& graph,vector<int>&col,int i)
    {
        queue<int> q;
        q.push(i);
        col[i]=0;
        while(!q.empty())
        {
            int x=q.front();
            q.pop();
            for(auto it:graph[x])
            {
                if(col[it]==-1) 
                {
                    col[it]=!col[x];
                    q.push(it);
                }
                else
                {
                    if(col[it]==col[x]) return false;
                }
            }
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int> col(n,-1);
        for(int i=0;i<n;i++)
        {
            if(col[i]==-1)
            {
                if(bfs(graph,col,i)==false) return false;
            }
        }
        return true;
    }
};