//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    bool isvalid(int row,int col,int n,vector<int>& temp)
    {
        for(int i=0;i<temp.size();i++) // up and down
        {
            if(temp[i]==col+1) return false;
        }
    
        if(temp[row]!=-1) return false; //left and right
        
        int i=row,j=col;
        while(i>=0 and j<n) // top-right
        {
            if(temp[i] == j+1) return false;
            i--;
            j++;
        }
        // i=row,j=col;
        // while(i<n and j<n) //bottom-right
        // {
        //     if(temp[i] == j+1) return false;
        //     i++;
        //     j++;
        // }
        i=row,j=col;
        while(i>=0 and j>=0) //top-left
        {
            if(temp[i] == j+1) return false;
            i--;
            j--;
        }
        // i=row,j=col;
        // while(i<n and j>=0) //bottom-left
        // {
        //     if(temp[i] == j+1) return false;
        //     i++;
        //     j--;
        // }
        
        return true;
    }
    void fun(int row,int n,vector<vector<int>>& ans,vector<int>& temp)
    {
        
        if(row>=n)
        {
            ans.push_back(temp);
            return ;
        }
        for(int j=0;j<n;j++)
        {
            if(isvalid(row,j,n,temp))
            {
                temp[row]=j+1;
                fun(row+1,n,ans,temp);
                temp[row]= -1;
            }
        }
    }
    vector<vector<int>> nQueen(int n) {
        vector<vector<int>> ans;    vector<int> temp(n,-1);
        for(int i=0;i<n;i++)
        {
            fun(i,n,ans,temp);
            break;
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        
        Solution ob;
        vector<vector<int>> ans = ob.nQueen(n);
        if(ans.size() == 0)
            cout<<-1<<"\n";
        else {
            for(int i = 0;i < ans.size();i++){
                cout<<"[";
                for(int u: ans[i])
                    cout<<u<<" ";
                cout<<"] ";
            }
            cout<<endl;
        }
    }
    return 0;
}
// } Driver Code Ends