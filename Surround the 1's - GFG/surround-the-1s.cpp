//{ Driver Code Starts

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
public:
    int row[8]={-1,-1,0,1,1,1,0,-1};
	int col[8]={0,1,1,1,0,-1,-1,-1};
    bool isvalid(int i, int j, int n, int m)
    {
        if(i<0 or j<0 or i>=n or j>=m) return false;
        return true;
    }
    bool even_check(int i, int j,int n, int m, vector<vector<int>>& matrix)
    {
        int count = 0;
        for(int k=0;k<8;k++)
        {
            int nrow = i+row[k];
            int ncol = j+col[k];
            if(isvalid(nrow,ncol,n,m) and matrix[nrow][ncol]==0) count++;
        }
        return (count>0 and count%2==0);
    }
    int Count(vector<vector<int> >& matrix) {
        // Code here
        int n = matrix.size(); int m = matrix[0].size();
        int count = 0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(matrix[i][j]==1) if(even_check(i,j,n,m,matrix)) count++;
            }
        }
        return count;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>> matrix(n, vector<int>(m,0));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> matrix[i][j];
			}
		}
		Solution ob;
		int ans = ob.Count(matrix);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends