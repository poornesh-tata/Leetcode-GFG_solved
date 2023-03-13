//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    bool isvalid(int i,int j,vector<vector<char>>& board)
    {
        int n=board.size(),m=board[0].size();
        if(i<0 or j<0 or i>=n or j>=m) return false;
        return true;
    }
    bool dfs(int i,int r,int c,vector<vector<char>>& board, vector<vector<int>> &vis,string word)
    {
        // cout<<i<<" "<<r<<" "<<c<<endl;
        vis[r][c]=1;
        int row[]={-1,0,1,0};
        int col[]={0,1,0,-1};
        for(int j=0;j<4;j++)
        {
            int nrow=r+row[j];
            int ncol=c+col[j];
            if(isvalid(nrow,ncol,board) and !vis[nrow][ncol] and board[nrow][ncol]==word[i+1])
            {
                if(dfs(i+1,nrow,ncol,board,vis,word)) return true;
            }
        }
        i++;
        if(i>=word.size())
        {
            return true;
        }
        return false;
    }
    bool isWordExist(vector<vector<char>>& board,string &word) {
        // Code here
        int n=board.size(),m=board[0].size();
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(board[i][j]==word[0])
                {
                    vector<vector<int>> vis(n,vector<int>(m,0));
                    if(dfs(0,i,j,board,vis,word)) return true;
                }
            }
        }
        return false;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<char>>board(n, vector<char>(m, '*'));
		for(int i = 0; i < n; i++)
			for(int j = 0; j < m; j++)
				cin >> board[i][j];
		string word;
		cin >> word;
		Solution obj;
		bool ans = obj.isWordExist(board, word);
		if(ans)
			cout << "1\n";
		else cout << "0\n";
	}
	return 0;
}
// } Driver Code Ends