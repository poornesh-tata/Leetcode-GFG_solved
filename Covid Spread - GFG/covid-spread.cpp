//{ Driver Code Starts
//Initial Template for C++


#include<bits/stdc++.h> 
using namespace std; 


// } Driver Code Ends
//User function Template for C++

class Solution {
public:
    int helpaterp(vector<vector<int>> hospital)
    {
        //code here
        int ans=0;
        int n=hospital.size();
        int m=hospital[0].size();
        queue<pair<pair<int,int>,int>>q;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(hospital[i][j]==2) q.push({{i,j},0});
            }
        }
        int row[]={-1,0,1,0};
        int col[]={0,1,0,-1};
        while(!q.empty())
        {
            pair<int,int> x=q.front().first;
            int y=q.front().second;
            ans=max(ans,y);
            q.pop();
            for(int i=0;i<4;i++)
            {
                int nrow=x.first+row[i];
                int ncol=x.second+col[i];
                if(nrow>=0 and nrow<n and ncol>=0 and ncol<m and hospital[nrow][ncol]==1)
                {
                    if(hospital[nrow][ncol]==1)
                    {
                        hospital[nrow][ncol]=2;
                        q.push({{nrow,ncol},y+1});
                    }
                }
            }
        }
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++) if(hospital[i][j]==1) return -1;
        }
        return ans;
    }
};


//{ Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int R;int C;
        
        cin>>R>>C;
        vector<vector<int>> hospital;
        int i,j;
        for(i=0;i<R;i++)
         {   vector<int> temp;
             for(j=0;j<C;j++)
            {
                int k;
                cin>>k;
                temp.push_back(k);
            }
            hospital.push_back(temp);
         }
        
        Solution ob;
        int ans = ob.helpaterp(hospital);
        cout << ans << endl;
    }
    return 0;
}
// } Driver Code Ends