//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    bool isvalid(int x, int y, int m, int n)
    {
        if(x<0 or x>=m or y<0 or y>=n) return false;
        return true;
    }
    bool fun(int r,int c,int n,int m,int index,vector<vector<char>>& grid,vector<vector<int>> vis,string& str,string& word)
    {
        if(index>=word.size()) return true;
        vis[r][c]=1;
        if(str.size()==0)
        {
            for(int i=-1;i<=1;i++)
            {
                for(int j=-1;j<=1;j++)
                {
                    if(i==0 and j==0) continue;
                    int nrow = r+i;
                    int ncol = c+j;
                    if(isvalid(nrow,ncol,n,m) and grid[nrow][ncol]==word[index] and !vis[nrow][ncol])
                    {
                        if(i==-1)
                        {
                            if(j==-1) str+='a';
                            if(j==0) str+='b';
                            if(j==1) str+='c';
                        }
                        if(i==0)
                        {
                            if(j==-1) str+='d';
                            if(j==1) str+='e';
                        }
                        if(i==1)
                        {
                            if(j==-1) str+='f';
                            if(j==0) str+='g';
                            if(j==1) str+='h';
                        }
                        if(fun(nrow,ncol,n,m,index+1,grid,vis,str,word)) return true;
                    }
                }
            }
        }
        else
        {
            char ch = str.back();
            int nrow = 0; int ncol = 0;
            if(ch=='a') { nrow = r-1;  ncol = c-1; }
            if(ch=='b') { nrow = r-1;  ncol = c; }
            if(ch=='c') { nrow = r-1;  ncol = c+1; }
            if(ch=='d') { nrow = r;  ncol = c-1; }
            if(ch=='e') { nrow = r;  ncol = c+1; }
            if(ch=='f') { nrow = r+1;  ncol = c-1; } 
            if(ch=='g') { nrow = r+1;  ncol = c; }
            if(ch=='h') { nrow = r+1;  ncol = c+1; }
            if(isvalid(nrow,ncol,n,m) and grid[nrow][ncol]==word[index] and !vis[nrow][ncol])
            {
                if(fun(nrow,ncol,n,m,index+1,grid,vis,str,word)) return true;
            }
        }
        return false;
    }
	vector<vector<int>>searchWord(vector<vector<char>>grid, string word){
	    // Code here
	    int n = grid.size();    int m = grid[0].size();
	    vector<vector<int>> vis(n,vector<int>(m,0));
	    vector<vector<int>> ans;    string str = "";
	    for(int i=0;i<n;i++)
	    {
	        for(int j=0;j<m;j++)
	        {
	            str = "";
	            if(grid[i][j]==word[0])
	            {
	                if(fun(i,j,n,m,1,grid,vis,str,word))
	                {
	                    ans.push_back({i,j});
	                }
	            }
	        }
	    }
	    return ans ;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<char>>grid(n, vector<char>(m,'x'));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++)
				cin >> grid[i][j];
		}
		string word;
		cin >> word;
		Solution obj;
		vector<vector<int>>ans = obj.searchWord(grid, word);
		if(ans.size() == 0)
		{
		    cout<<"-1\n";
		}
		else
		{
		    for(auto i: ans){
			for(auto j: i)
				cout << j << " ";
			cout << "\n";
		    }
		}
		
		
	}
	return 0;
}
// } Driver Code Ends