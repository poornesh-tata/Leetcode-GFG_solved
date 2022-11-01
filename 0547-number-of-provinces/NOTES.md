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