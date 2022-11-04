class Solution {
public:
    int bfs(vector<vector<int>>table)
    {
        int max=0;
        int n=table.size();
        int m=table[0].size();
        queue<pair<pair<int,int>,int>>q;
        for(int i=0;i<n;i++)
	    {
	        for(int j=0;j<m;j++)
	        {
	            if(table[i][j]==2)
	            {
	                q.push({{i,j},0});
	            }
	        }
	    }
	    while(!q.empty())
	    {
	        pair<int,int> x=q.front().first;
	        int y=q.front().second;
	        if(y>max) max=y;
            table[x.first][x.second]=2;
	        q.pop();
	        int row[]={-1,0,1,0};
	        int col[]={0,1,0,-1};
	        for(int i=0;i<4;i++)
	        {
	            int nrow=x.first+row[i];
	            int ncol=x.second+col[i];
	            if(nrow>=0 and nrow<n and ncol>=0 and ncol<m and
	                                     table[nrow][ncol]==1)
	            {
	                table[nrow][ncol]=2;
	                q.push({{nrow,ncol},y+1});
	            }
	        }
	    }
	    for(int i=0;i<n;i++)
	    {
	        for(int j=0;j<m;j++)
	        {
	            if(table[i][j]==1)
	            {
	                return -1;
	            }
	        }
	    }
	    return max;
    }
    int orangesRotting(vector<vector<int>>& grid) {
        vector<vector<int>> table=grid;
        return bfs(table);
    }
};