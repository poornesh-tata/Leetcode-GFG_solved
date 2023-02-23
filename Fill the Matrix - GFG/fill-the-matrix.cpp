//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function Template for C++

class Solution{   
public:
    int minIteration(int N, int M, int x, int y){    
        // code here
        vector<vector<int>> vis(N,vector<int>(M,0));
        int ans=0;
        queue<pair<pair<int,int>,int>> q;
        q.push({{x-1,y-1},0});
        vis[x-1][y-1]=1;
        int row[]={-1,0,1,0};
        int col[]={0,1,0,-1};
        while(!q.empty())
        {
            int x=q.front().first.first;
            int y=q.front().first.second;
            int z=q.front().second;
            ans=max(ans,z);
            q.pop();
            for(int i=0;i<4;i++)
            {
                int nrow=x+row[i];
                int ncol=y+col[i];
                if(nrow>=0 and ncol>=0 and nrow<N and ncol<M and !vis[nrow][ncol])
                {
                    q.push({{nrow,ncol},z+1});
                    vis[nrow][ncol]=1;
                }
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N, M, x, y;
        cin >> N >> M;
        cin >> x >> y;
        
        Solution ob;
        cout << ob.minIteration(N, M, x, y) << endl;
    }
    return 0; 
} 
// } Driver Code Ends