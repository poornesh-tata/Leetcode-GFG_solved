//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution{
    public:
    bool isvalid(int x, int y, int n)
    {
        if(x<0 or x>=n or y<0 or y>=n) return false;
        return true;
    }
    void fun(int i,int j,int n,vector<vector<int>> &m,vector<vector<int>> &vis,vector<string>& ans,string& str,int row[],int col[])
    {
        if(i==n-1 and j==n-1) 
        {
            ans.push_back(str);
        }
        vis[i][j]=1;
        for(int k=0;k<4;k++)
        {
            int nrow = i+row[k];
            int ncol = j+col[k];
            if(isvalid(nrow,ncol,n) and m[nrow][ncol]==1 and !vis[nrow][ncol])
            {
                if(k==0) str+='U';
                else if(k==1) str+='R';
                else if(k==2) str+='D';
                else str+='L';
                fun(nrow,ncol,n,m,vis,ans,str,row,col);
                str.pop_back();
                vis[nrow][ncol]=0;
            }
        }
    }
    vector<string> findPath(vector<vector<int>> &m, int n) {
        if(m[0][0]==0) return {};
        int row[]={-1,0,1,0};
        int col[]={0,1,0,-1};
        vector<vector<int>> vis(n,vector<int>(n,0));    vector<string> ans;
        
        string str = "";
        fun(0,0,n,m,vis,ans,str,row,col);
        return ans;
    }
};

    


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int> (n,0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m, n);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends